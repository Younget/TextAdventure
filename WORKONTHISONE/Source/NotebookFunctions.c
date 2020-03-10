/******************************************************************************
filename    NotebookFunctions.c
author      Nick Faterweather
DP email    nick.fayerweather@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "notebook".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "NotebookFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the ticket is taken. */
void Notebook_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the ticket might be used, whenever it is picked up. */
	printf("You pick up the notebook with a fountain pen attached. The cover has a linkin park logo on it. Strange. This might come in handy later.\n");
}


/* Helper: The action performed when the ticket is used. */
void Notebook_Read(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* notebook; /* The notebook in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the notebook out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the notebook - inform the user of the problem and take no action */
		printf("You must have the notebook before you can read it.\n");
		return;
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

		/* Find the notebook in the player's inventory - it should be there, since we are in the Inventory context */
		notebook = ItemList_FindItem(gameState->inventory, "notebook");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);
		if (gameState->farthestRoom >= 1) {
			printf("There is vegitaion everywhere. It seems like this park has been abandoned for years. There are some statues that are covered by moss.");
		}
		else return;
		if (gameState->farthestRoom >= 2) {
			printf("There is graffiti fading on the walls. suprisingly there is no trash laying on the ground.");
		}
		else return;
		if (gameState->farthestRoom >= 3) {
			printf("The lights are dimmed and the shelves are mainly empty. All of the nicotine patches are gone. Why?");
		}
		else return;
		if (gameState->farthestRoom >= 4) {
			printf("There are empty pill bottles over the counter. All of the laxatives are gone. Strange ");
		}
		else return;
		if (gameState->farthestRoom >= 5) {
			printf("The subway look rusty, the gate, the tracks and the ticket booth. Ohh a pack of gum in the ticket booth. You can't reach it. ");
		}
		else return;
		if (gameState->farthestRoom >= 6) {
			printf("The streets are empty but there are a few cars. One of them is an all black old restored muscle car. Neat.");
		}
		else return;
		if (gameState->farthestRoom >= 7) {
			printf("The hospital is one of the few buildings with power. Must be becuase of the backup generators. Weird. No bodies whatsoever");
		}
		else return;
		if (gameState->farthestRoom >= 8) {
			printf("There is a syringe that is glowing magenta labeled EXPERIMENTAL on the table, along with a keycard as well as some empty ones laying on the ground. There is a projector displaying graphs and charts. It appears it showing information about the virus.");
		}
		else return;
		if (gameState->farthestRoom >= 9) {
			printf("It looks clean. As if somone cleaned it yesterday. You see a piece of paper on the desk.");
		}
		else return;
		if (gameState->farthestRoom >= 10) {
			printf("You feel like you know this place.You start to recognize everything in the room.The posters, the kitchen, the laptop and the flatscreen 40 TV. Everything is clicking now.");
		}
		else return;

	}
}

/* Build a "ticket" object */
Item* Notebook_Build()
{
	/* Create a "ticket" item, using the functions defined in this file */
	return Item_Create("notebook", "A notebook", true, Notebook_Read, Notebook_Take, NULL);
}