/******************************************************************************
filename    KeycardFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "keycard".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "KeycardFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the keycard is taken. */
void Keycard_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the keycard might be used, whenever it is picked up. */
	printf("You pick up the keycard. It has your name on it.\n");
}


/* Helper: The action performed when the keycard is used. */
void Keycard_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* keycard; /* The keycard in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the keycard out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the keycard - inform the user of the problem and take no action */
		printf("You must have the keycard before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 8 || gameState->currentRoomIndex != 5)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("There's no use for the keycard here.\n");
		return;
	}
	else if (gamestate->currentRoomIndex = 8)
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* add exit into secure area */
		Room_AddRoomExit(WorldData_GetRoom(worldData, gameState->currentRoomIndex), "west", 9);

		/* Find the brick in the player's inventory - it should be there, since we are in the Inventory context */
		keycard = ItemList_FindItem(gameState->inventory, "keycard");

		/* Tell the user what they did */
		printf("You swipe the keycard on the door, and it swings open.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "You walk back into the lab. The door to the main hospital is south.\n");

	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}
		/* add exit into apartment */
		Room_AddRoomExit(WorldData_GetRoom(worldData, gameState->currentRoomIndex), "west", 10);

		/* Find the brick in the player's inventory - it should be there, since we are in the Inventory context */
		keycard = ItemList_FindItem(gameState->inventory, "keycard");

		/* Tell the user what they did */
		printf("You swipe the keycard on your door and it unlocks.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "You walk back into your apartment. The subway is west from here.\n");

	}
}


/* Build a "keycard" object */
Item* Keycard_Build()
{
	/* Create a "keycard" item, using the functions defined in this file */
	return Item_Create("keycard", "A keycard used to get into the secure area", true, Keycard_Use, Keycard_Take, NULL);
}