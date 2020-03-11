/******************************************************************************
filename    LaptopFunctions.c
author      Ethan Young
DP email    ethany905@gmail.com
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "LaptopFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "PasswordFunctions.h" /* Password_Build */
#include <stdio.h>

typedef struct WorldData WorldData;

void Laptop_Type(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* Set up variables*/
	char string[256];
	char* passWord = "immortal";

	/*ask for the string to encrypt and store it in string*/
	printf("Please enter the password:\n");
	fgets(string, 256, stdin);

	if (strcmp(string, passWord) == 1)
	{
		printf("You log in.\n You find out that all of your files are missing or have compile errors except one folder.\n");
		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);
	}
	return;
}


/* Build a "exit door" object */
Item* Laptop_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("laptop", "This laptop must be yours?\n", false, NULL, NULL, NULL, NULL, NULL, Laptop_Type);
}