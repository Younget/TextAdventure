/******************************************************************************
filename    SyringeFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Rotten Food Item in the game
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "HospitalBillFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

/* Helper: The action performed when the bill is taken. */
void Syringe_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the newspaper might be used, whenever it is picked up. */
	printf("It appears to be a medicinal syringe radiating with an odd magenta glow\n");
}
/* Helper: The action perfromed when the bill is read*/
void Syringe_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("I don't believe you have any syringes to use.\n");
		return;
	}

	else
	{
		printf("----------YOU DIED-----------\n");
		printf("Whether or not your mother told you not to use random syringes is not my business,\n as you plugne the needle into your arm and squeeze the magenta liquid into your arm it feels nice at first, you take a few steps forward and start tripping, you fall flat on your face hitting the floor and falling asleep forever.NIGHTY NIGHT\n");
		printf("It may benefit you to keep away from using random needles in your daily life. Just a word of advice and caution.\n");
	}
}

Item* Syringe_Build()
{
	/* Create a "Hospital Bill" item, using the functions defined in this file */
	return Item_Create("syringe", "It appears to be a medicinal syringe radiating with an odd magenta glow\n", true, Syringe_Use, Syringe_Take, NULL, NULL, NULL, NULL);
}