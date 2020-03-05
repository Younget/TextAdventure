/******************************************************************************
filename    HospitalBill.c
author      Nick Fayerweather
DP email    nick.fayerweather@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the Hospital Bill Iteam in the game

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
void HospitalBill_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the newspaper might be used, whenever it is picked up. */
	printf("The bill appears to be oddly recent besides a few specks of dust.\n");
}
/* Helper: The action perfromed when the bill is read*/
void HospitalBill_Read(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You must have the Hospital Bill before you can use it.\n");
		return;
	}
	printf("After further inspection of the bill, it appears that the cost is 1 million dollars for a drug called \n ");
}

Item* HospitalBill_Build()
{
	/* Create a "Hospital Bill" item, using the functions defined in this file */
	return Item_Create("hospital bill", "Your name is on the bill for an experamental drug\n", true, NULL , HospitalBill_Take, NULL);
}