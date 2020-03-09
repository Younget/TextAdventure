/******************************************************************************
filename    ReadCommandHandler.c
author      Esther Strathy

Brief Description:
This file defines functions that handle the "read" user command, which allows the player to read things

******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "GoCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetNextRoomIndex, Room_Print, INVALID_DIRECTION_ID */

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;
/*Handles Read Command which displays text for objects*/
void HandleReadCommand()
{

}