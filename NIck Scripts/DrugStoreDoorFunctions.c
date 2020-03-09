/******************************************************************************
filename    DrugStoreDoorFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "DrugStoreDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "SledgehammerFunctions.h" /* Sledgehammer_Build */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void DrugStoreDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* sledgehammer; /* the egg in the user's inventory */

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the egg in the user's inventory */
	sledgehammer = ItemList_FindItem(gameState->inventory, "sledgehammer");

	/* check if both items are in the user's inventory */

		/* both items were not found - tell the user about the problem and take no further action */
		printf("Door stuck! Door stuck! You have no strength whatsoever, you need to use a tool to get by.\n");
		return;
}

void DrugStoreDoor_Smash(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* sledgehammer; /* the sledgehammer in the user's inventory */

	/* find the sledgehammer in the user's inventory */
	Item* sledgehammer = ItemList_FindItem(gameState->inventory, "sledgehammer");

	/* Checks whether sledgehammer is actually there*/
	if (sledgehammer != NULL)
	{
		printf("Swing and a miss. Your hand eye cordination is off today. You go for another try. Swing and a miss. The sledgehammer gose flying into the sewer system.\n ");
		printf("Nice?");
	}
	return;
}


/* Build a "exit door" object */
Item* DrugStoreDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("barricaded door", "The drug store door has a flimsy barricade that could be destroyed with critical hit.\n", false, DrugStoreDoor_Use, NULL, NULL, NULL, DrugStoreDoor_Smash, NULL);
}