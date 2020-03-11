/******************************************************************************
filename    TypeCommandHandler.c
author      Esther Strathy
DP email    esther.strathy@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
Command handler for "type" function for typing the password into the laptop in the final room 
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/

#include "stdafx.h" /* NULL, printf */
#include "TypeCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_Print, Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h"
#include <stdio.h>  /*printf*/
#include "GameFlags.h" /* GameFlags_IsInList */

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;
typedef struct Item Item; 

void HandleTypeCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* typeItem; /* the item removed from the room and added to the user's inventory */
	Room* room; /* the current room */
	ItemList** roomItemPtr; /* the list of items in the current room */
	ItemFunc typeFunc; /* The function to be called for the given item when it is taken */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}
	/* retrieve the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/*checks if object is in inventory*/

	/* get the current room's item list */
	roomItemPtr = Room_GetItemList(room);
	if (roomItemPtr == NULL)
	{
		return; /* there was no room or item list pointer - something is wrong.  take no action */
	}

	/* find the item in the current room's item list, using the command noun */
	typeItem = ItemList_FindItem(*roomItemPtr, command->noun);
	if (typeItem == NULL)
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not see a %s here.\n", command->noun);
		return;
	}
	typeFunc = Item_GetTypeFunc(typeItem);
	if (typeFunc != NULL)
	{
		/* call the drop function with the Inventory context, since that's where the item was */
		typeFunc(CommandContext_Item_Inventory, gameState, worldData);
	}
	gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "Unlocked");
	return; 
}