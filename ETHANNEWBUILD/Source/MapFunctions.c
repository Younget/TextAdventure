/******************************************************************************
filename    HospitalBill.c
author      Nick Fayerweather
DP email    nick.fayerweather@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Hospital Bill Iteam in the game
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "MapFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


void Map_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the newspaper might be used, whenever it is picked up. */
	printf("The map appears to be new and unused \n");
}

void Map_Read(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("\n");
		return;
	}
	printf(" \n ");
}
Item* Map_Build()
{
	/* Create a "Hospital Bill" item, using the functions defined in this file */
	return Item_Create("map", "you pick up a map of the city\n", true, NULL, Map_Take, NULL, Map_Read, NULL, NULL);
}