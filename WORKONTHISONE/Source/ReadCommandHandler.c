/******************************************************************************
filename    ReadCommandHandler.c
author      Esther Strathy
DP email    esther.strathy@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
Command handler for "read" function which allows player to read text off objects 
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "ReadCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_Print, Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h"
#include <stdio.h>  /*printf*/


/*Handles Read Command which displays text for objects*/
void HandleReadCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{

	Item* readItem; /* the item removed from the room and added to the user's inventory */
	Room* room; /* the current room */
	ItemList** roomItemPtr; /* the list of items in the current room */
	ItemFunc readFunc; /* The function to be called for the given item when it is taken */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* retrieve the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/*checks if object is in inventory*/
	readItem = ItemList_FindItem(gameState->inventory, command->noun);
	if (readItem != NULL)
	{
		printf("(in your inventory)\n"); /* clarify the target for the user */
		/* an item matching the noun was found in the user's inventory - print its description */
		Item_Print(readItem);
		return;
	}

	/* get the current room's item list */
	roomItemPtr = Room_GetItemList(room);
	if (roomItemPtr == NULL)
	{
		return; /* there was no room or item list pointer - something is wrong.  take no action */
	}

	/* find the item in the current room's item list, using the command noun */
	readItem = ItemList_FindItem(*roomItemPtr, command->noun);
	if (readItem == NULL)
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not see a %s here.\n", command->noun);
		return;
	}
	readFunc = Item_GetReadFunc(readItem);
	if (readFunc != NULL)
	{
		/* call the drop function with the Inventory context, since that's where the item was */
		readFunc(CommandContext_Item_Inventory, gameState, worldData);
	}
	printf("%s",readItem->text);
}