/******************************************************************************
filename    GameStateFactory.c
author     Ethan Young
DP email    ethan.young@digipen.edu
Brief Description:
This file implements the GameState factory, which creates the game state objects used
in this game.
All content � 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "GameStateFactory.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_Create */


/* Create the game state for a new game */
GameState* CreateInitialGameState()
{
	GameState* initialGameState; /* the new GameState object we will return */
	
	/* create an empty GameState object */
	initialGameState = GameState_Create();

	/* the user starts with a score of 0 */
	initialGameState->score = 0;

	/* the user starts in room 0 */
	initialGameState->currentRoomIndex = 0;

	/* return the new object */
	return initialGameState;
}