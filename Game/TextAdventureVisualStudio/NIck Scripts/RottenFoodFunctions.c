/******************************************************************************
filename    RottenFoodFunctions.c
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
void RottenFood_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the newspaper might be used, whenever it is picked up. */
	printf("Looks like some muffin with what looks like blueberries or superfluous mold in the wrapper or something. Yum?\n");
}
/* Helper: The action perfromed when the bill is read*/
void RottenFood_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("It smells bad and looks bad. Good thing your not hungry.\n");
		return;
	}

	else
	{
		printf("----------YOU DIED-----------\n");
		printf("Upon eating the rotten food, you start freaking out and seeing things that you cannot explain, you also see the expiration date on the wrapper and you immediately regret everything that you have done in life.\n");
		printf("Those were in fact, not blueberries......\n");
	}
}

Item* RottenFood_Build()
{
	/* Create a "Hospital Bill" item, using the functions defined in this file */
	return Item_Create("rotten food", "Looks like some muffin with what looks like blueberries or superfluous mold\n", true, RottenFood_Use, RottenFood_Take, NULL, NULL, NULL, NULL);
}