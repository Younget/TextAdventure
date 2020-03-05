/*
TypeCommandHandler.c
By: Esther Strathy 
3/4/2020
Description: handles type commands which allows player to input password into laptop at the end of the game
*/


#include "stdafx.h" /* NULL, printf */
#include "GoCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetNextRoomIndex, Room_Print, INVALID_DIRECTION_ID */

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;

/*void HandleTypeCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{

}*/