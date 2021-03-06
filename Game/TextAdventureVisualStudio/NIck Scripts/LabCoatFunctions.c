/******************************************************************************
filename    LabCoatFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Hospital Bill Iteam in the game
All content � 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "LabCoatFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


void LabCoat_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the newspaper might be used, whenever it is picked up. */
	printf("The map appears to be dated but unused \n");
}

void LabCoat_Read(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You cannot read what you don't have, better find that newspaper.\n");
		return;
	}

	else
	{
		printf("Upon further inspection, you recognize that the small blue text as your name!\nWhat were you doing here?\n");
	}
}

void LabCoat_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("Instead of actually having a labcoat, you put on your imaginary labcoat. You'd probably have better use with a real one though.\n");
		return;
	}

	else
	{
		printf("You decide the best course of action is to wear the labcoat. Congratulations, you now have a swanky dated labcoat");
	}
}


Item* LabCoat_Build()
{
	/* Create a "Hospital Bill" item, using the functions defined in this file */
	return Item_Create("labcoat", "you pick up a somewhat dusty labcoat, it has a small blue text on it. \n", true, LabCoat_Use, LabCoat_Take, NULL, LabCoat_Read, NULL, NULL);
}