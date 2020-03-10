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
		printf("You cannot enter this barricaded door without excessive force, which your body seemingly lacks.\n");
		return;
}

void DrugStoreDoor_Smash(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* sledgehammer; /* the sledgehammer in the user's inventory */

	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the sledgehammer in the user's inventory */
	sledgehammer = ItemList_FindItem(gameState->inventory, "sledgehammer");

	/* Checks whether sledgehammer is actually there*/
	if (sledgehammer != NULL)
	{
		printf("With a mighty swing, you miss your target and the sheer force makes you spin one-hundred-eighty degrees. Your body clashes into the weak barricade and the sledgehammer is left flying off into a distant window.\n ");
		printf("Yay?");
	}
	/* Add to the player's score */
	GameState_ChangeScore(gameState, 10);
	return;
}


/* Build a "exit door" object */
Item* DrugStoreDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("barricaded door", "The drug store door has a flimsy barricade that could be destroyed with enough force\n", false, DrugStoreDoor_Use, NULL, NULL, NULL, DrugStoreDoor_Smash, NULL);
}