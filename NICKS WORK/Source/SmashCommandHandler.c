/******************************************************************************
filename    SmashCommandHandler.c
author      Esther Strathy
DP email    esther.strathy@digipen.edu
Brief Description:
Command handler for the "Smash" command 
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/

#include "stdafx.h" /* NULL, printf */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetNextRoomIndex, Room_Print, INVALID_DIRECTION_ID */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /*includes item*/
#include "DropCommandHandler.h"
#include "GameFlags.h" /* GameFlags_IsInList */


typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;

void HandleSmashCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* smashItem; /* the item removed from the room and added to the user's inventory */
	Room* room; /* the current room */
	ItemList** roomItemsPtr; /* the list of items in the current room */
	ItemFunc smashFunc; /* The function to be called for the given item when it is taken */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* retrieve the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* get the current room's item list */
	roomItemsPtr = Room_GetItemList(room);
	if (roomItemsPtr == NULL)
	{
		return; /* there was no room or item list pointer - something is wrong.  take no action */
	}


	/* find the item in the current room's item list, using the command noun */
	smashItem = ItemList_FindItem(*roomItemsPtr, command->noun);
	if (smashItem == NULL)
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not see a %s here.\n", command->noun);
		return;
	}

	/* get the "smash" function for this item, if any (it is optional) */
	smashFunc = Item_GetSmashFunc(smashItem);
	if (smashFunc != NULL)
	{
		/* call the drop function with the Inventory context, since that's where the item was */
		smashFunc(CommandContext_Item_Inventory, gameState, worldData);
	}
	
	gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "Broken");
	return;
}
