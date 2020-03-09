/******************************************************************************
filename    TicketFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "ticket".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "TicketFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the ticket is taken. */
void Ticket_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the ticket might be used, whenever it is picked up. */
	printf("You pick up the ticket. Don't lose it.\n");
}


/* Helper: The action performed when the ticket is used. */
void Ticket_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* ticket; /* The brick in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the ticket out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the ticket - inform the user of the problem and take no action */
		printf("You must have the subway ticket before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 5)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("Why would you use the ticket here? Why?\n");
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

		/* Find the ticket in the player's inventory - it should be there, since we are in the Inventory context */
		ticket = ItemList_FindItem(gameState->inventory, "ticket");

		/* Tell the user what they did */
		printf("You insert the ticket into the ticket machine, and the subways doors open. You walk in, noticing a map on the wall. Times Square is to the north, and someplace oddly familiar is to the east.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "You walk back onto the subway. You can go: West to the park, north to Times Square, or east to somewhere oddly familiar...\n");

	}
}

/* Build a "ticket" object */
Item* Ticket_Build()
{
	/* Create a "ticket" item, using the functions defined in this file */
	return Item_Create("ticket", "A subway ticket", true, Ticket_Use, Ticket_Take, NULL);
}