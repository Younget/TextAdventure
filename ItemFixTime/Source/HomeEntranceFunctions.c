/******************************************************************************
filename    HomeEntranceFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "HomeEntranceFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "KeycardFunctions.h" /* Sledgehammer_Build */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void HomeDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* keycard; /* the item in the user's inventory */ 

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the item in the user's inventory */
	keycard = ItemList_FindItem(gameState->inventory, "keycard"); 
	
	
	/* TODO: Determine either item found or room passed */
	if(keycard != NULL)
	{
		printf("Finally, with your newfound keycard and knowledge, you slide the keycard in the slot. A short 'Beep' is uttered out, and the door magically disappears from existance.\nSmall particles of your door are now in the wild, but you are now home.");
		return;
	}
	else
	{
		printf("You find your way to what you believe to be your home. Without looking, you try the handle and it breaks off.\nAfter close inspection, you realize that there is a keycard reader to the left of the handle.");
		return;
	}
}

/* Build a "exit door" object */
Item* HomeDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("home door", "It seems to be your home, it has a handle and a keycard reader to the left of the handle.\n", false, HomeDoor_Use, NULL, NULL, NULL, NULL, NULL);
}