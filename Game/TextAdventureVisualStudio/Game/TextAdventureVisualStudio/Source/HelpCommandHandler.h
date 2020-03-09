/******************************************************************************
filename    HelpCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "help" user command, which outputs 
a list of the available verbs.
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "help" command, whic outputs a list of available verbs */
void HandleHelpCommand(CommandData* command, GameState *gameState, WorldData *worldData);