/******************************************************************************
filename    LabDoorFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "lab door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "DrugStoreDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "KeycardFunctions.h" 

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void LabDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* keycard; /* the keycard in the user's inventory */

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the keycard in the user's inventory */
	keycard = ItemList_FindItem(gameState->inventory, "keycard");

	/* check if both items are in the user's inventory */
	if (keycard != NULL)
	{
		printf("You cannot enter this barricaded door without excessive force, which your body seemingly lacks.\n");
	}
	return;
}


/* Build a "exit door" object */
Item* LabDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("lab door", "A locked lab door that has a little slot for a card.\n", false, LabDoor_Use, NULL, NULL, NULL, NULL, NULL);
}