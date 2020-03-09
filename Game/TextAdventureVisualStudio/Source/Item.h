/******************************************************************************
filename    Item.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the Item interface, which is used to manage items in the game.
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#pragma once
#include "stdafx.h" /* bool */
#include "CommandContext.h" /* enum CommandContext */

/* the maximum length of an item's name */
#define MAX_ITEM_NAME_LENGTH 16 

/* the maximum length of an item's description */
#define MAX_ITEM_DESCRIPTION_LENGTH 128

#define MAX_TEXT_LENGTH 256

typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Forward declaration for the Item type */
typedef struct Item Item;

/* The function pointer type for item-operation functions */
typedef void(*ItemFunc)(CommandContext context, GameState* gameState, WorldData* worldData);


/* Create a new Item object with the provided data */
Item* Item_Create(const char* name, const char* description, bool isCarryable, ItemFunc useFunc, ItemFunc takeFunc, ItemFunc dropFunc, ItemFunc readFunc, ItemFunc smashFunc, ItemFunc typeFunc);

/* Free the memory associated with a given Item object */
void Item_Free(Item** itemPtr);

/* Retrieve the name of the given item */
const char* Item_GetName(Item* item);

/* Retrieve the description of the given item */
const char* Item_GetDescription(Item* item);

/* Retrieve whether the item is carryable */
bool Item_IsCarryable(Item* item);

/* Retrieve the "use" function for this item, if any */
ItemFunc Item_GetUseFunc(Item* item);

/* Retrieve the "take" function for this item, if any */
ItemFunc Item_GetTakeFunc(Item* item);

/* Retrieve the "drop" function for this item, if any */
ItemFunc Item_GetDropFunc(Item* item);

ItemFunc Item_GetReadFunc(Item* item);

ItemFunc Item_GetSmashFunc(Item* item);

ItemFunc Item_GetTypeFunc(Item* item);

/* Print a description of the item to standard output */
void Item_Print(Item* item);

typedef struct Item
{
	char name[MAX_ITEM_NAME_LENGTH];	/* the name of the item, used for noun matching */
	char description[MAX_ITEM_DESCRIPTION_LENGTH];	/* a description of the item */
	char text[MAX_TEXT_LENGTH]; /* some objects have text that can be read off them */
	bool isCarryable;	/* if true, the item can be put in the user's inventory*/
	ItemFunc useFunc;	/* a function called when the user uses this item, if any */
	ItemFunc takeFunc;	/* a function called when the user takes this item, if any */
	ItemFunc dropFunc;	/* a function called when the user uses this item, if any */
	ItemFunc readFunc;  /* a function called when user reads item */
	ItemFunc smashFunc; /* a function called when user smashes an item*/
	ItemFunc typeFunc;  /* a function called when user wants to type something */
} Item;