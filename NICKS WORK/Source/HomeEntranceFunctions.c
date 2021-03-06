/******************************************************************************
filename    SubwayDoorFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
Brief Description:
This file defines the functions to create a specific item, the "exit door".
All content � 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "DrugStoreDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "SledgehammerFunctions.h" /* Sledgehammer_Build */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void HomeDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* Item* subwayticket; /* the item in the user's inventory */ 

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the item in the user's inventory */
	/* subwayticket = ItemList_FindItem(gameState->inventory, "subway ticket"); */
	
	
	/* TODO: Determine either item found or room passed */

}

/* Build a "exit door" object */
Item* HomeDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("subway entrance", "The subway entrance seems to be locked by a gate, a sign beside the gate says 'You need a ticket to enter the station'.\nLooks like you need a ticket\n", false, HomeDoor_Use, NULL, NULL, NULL, NULL, NULL);
}