/******************************************************************************
filename    SmashCommandHandler.h
author      Esther Strathy
DP email    esther.strathy@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
Header file for the "Smash" command 
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/


#pragma once
typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;

void HandleSmashCommand(CommandData* command, GameState* gameState, WorldData* worldData);
