/******************************************************************************
filename    PasswordFunctions.c
author      Ethan Young
DP email    ethan.young@digipen.edu but please use ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "password".

******************************************************************************/

#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PasswordFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

/* Helper: The action performed when the newspaper is taken. */
void Password_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("You wonder what this password is for, might give a clue to whats happened to everyone\n");
}

/* Helper: This action is performed when the newspaper is read. */
void Password_Read(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You cannot read what you don't have, better find that password kiddo.\n");
		return;
	}
	else
	{
		printf("Upon inspecting the password, you determine that it is 'password'.\nI bet this is the same type of person that accepts all terms and conditions without looking through it.\n");
	}
}

Item* Password_Build()
{
	/* Create a "newspaper" item, using the functions defined in this file */
	return Item_Create("password", "A password crudely written on a shriveled lump of paper", true, NULL, Password_Take, NULL, Password_Read, NULL, NULL);
}