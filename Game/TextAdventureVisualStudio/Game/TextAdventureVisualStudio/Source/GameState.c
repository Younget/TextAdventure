/******************************************************************************
filename    GameState.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the GameState interface, which is used to reflect the user state
in the game.
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
/* from GameState.h: stdafx.h, used here for NULL, malloc/free, printf */
#include "GameState.h" /* Function declarations */
#include "ItemList.h" /* ItemList_Free */
#include "GameFlags.h" /* GameFlags_Free */


/* Create an empty game state object */
GameState* GameState_Create()
{
	GameState* gameState; /* the new object we will return */

	/* allocate memory for the new object */
	gameState = (GameState*)malloc(sizeof(GameState));
	if (gameState == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* assign empty values to all members */
	gameState->score = 0;
	gameState->currentRoomIndex = 0;
	gameState->inventory = NULL;
	gameState->gameFlags = NULL;
	gameState->isRunning = true;

	/* return the new object */
	return gameState;
}


/* Free the memory associated with a game-state object */
void GameState_Free(GameState** gameStatePtr)
{
	/* safety check on the parameters */
	if ((gameStatePtr == NULL) || (*gameStatePtr == NULL))
	{
		return; /* take no action if no valid object was provided */
	}

	/* free the inventory */
	ItemList_Free(&(*gameStatePtr)->inventory);

	/* free the game flags */
	GameFlags_Free(&(*gameStatePtr)->gameFlags);

	/* free the object */
	free(*gameStatePtr);

	/* set the incoming pointer to NULL*/
	*gameStatePtr = NULL;
}


/* Modify the score, with appropriate user information */
void GameState_ChangeScore(GameState* gameState, int modifier)
{
	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if any action is needed*/
	if (modifier == 0)
	{
		return; /* no action needed */
	}

	/* modify the score */
	gameState->score += modifier;

	/* check if the modifier is positive or negative */
	if (modifier > 0)
	{
		/* the modifier was positive, so output a positive message */
		printf("You have gained %d points.  ", modifier);
	}
	else
	{
		/* the modifier was negative, so output a negative message */
		printf("You have lost %d points.  ", modifier);
	}

	/* output the new score total */
	printf("Your new score is %d.\n", gameState->score);
}


/* End the game, with appropriate user information */
void GameState_EndGame(GameState* gameState, const char* message)
{
	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* if a message was provided, output it now */
	if (message != NULL)
	{
		printf(message);
	}
	printf("I got into the laptop and it looks like I wrote some journal entries\n");
	scanf_s("");
	printf("May 14, 2043\n A new disease was just discovered in Russia—they’re calling it NDV-94. It’s been spreading rapidly and thousands are dying.Everyone here is terrified and we’ve been working hard in the lab to understand the virus and formulate a cure, but it’s slow going.So far, all we know is the first symptom tends to be headaches and shivering.As the disease progresses, people have been observed to lose motor control and begin to behave more erratically.The death rates have been high, and it appears to be very contagious, although we are unsure of how it spreads.\n");
	scanf_s("");
	printf("June 15, 2043\nNVD - 94 has reached the United States.Cities are quarantining, but there’s not much that can be done.It appears to travel through the air, so there’s a risk of getting it by just breathing next to someone.There’s already 1, 000 cases in New York City alone, and while we are getting close to a cure, we don’t know if it will be ready in time.\n");
	scanf_s("");
	printf("July 5, 2043\nWe’ve created a potential cure, but we are unsure if it’s safe to use and are beginning to conduct trials on mice.Hopefully it will be ready for human trials within the next few months, but the process is slow going.\n");
	scanf_s("");
	printf("July 28, 2043\nI don’t know what to do.I’ve been taking every precaution, but yesterday I noticed I had a splitting headache.I thought it was nothing, just a standard migraine, but then the shivering started.\nI’m going to die.\nIt’s a frightening thought, but what scares me most is knowing what’s coming in the next week.I’m going to go crazy and forget everything and one I know and love.I’m going to be violent and unpredictable.I’m going to lose my sense of self.\nAt this point I only see one option.\n");
	scanf_s("");
	printf("August 2, 2043\nI took the experimental cure.It wasn’t approved for human use, but I didn’t have a choice.So far, I’ve recovered, and have been under close observation to see the effects.\n");
	scanf_s("");
	printf("September 15, 2043\nA month after taking the cure, I appear to be fine, and more human trials are being conducted as I speak.People have hope again, and it’s a wonderful thing to see.\n");
	scanf_s("");
	printf("December 20, 2043\nIt’s been a while, but the cure appears to have been a success and is being mass distributed throughout the United States and the world.People will be saved, and I’m beyond proud of our work in the lab.\n");
	scanf_s("");
	printf("Jan 7, 2044\nMy memory has been foggy lately.I’ve been forgetting important events, and it’s been hard to think.It could be dementia, but I’m young and have had no family history, so I’m starting to think it’s a side effect of the cure to NDV - 94.\n");
	scanf_s("");
	printf("Jan 10, 2044\nMy memory has continued to deteriorate, and I often find I don’t know where I am.I forget names and faces.Sometimes I struggle to remember my own name, and those are the moments that scare me the most.Soon, I fear I will not remember who I am at all.\n");
	scanf_s("");
	printf("I guess after January 10th is when I disappeared and everyone else who took the cure also fell asleep...\n");
	scanf_s("");
	printf("Wait, it sounds like someone is calling out down the hall... I'm no longer alone");
	/* output the final score */
	printf("Your final score is %d.\n\n", gameState->score);

	/* output a clean goodbye message, so the user knows the game is exiting intentionally */
	printf("Goodbye!\n\n");
	printf("All content © 2020 DigiPen (USA) Corporation, all rights reserved.");

	/* set the isRunning state so the game quits on the next loop */
	gameState->isRunning = false;
}