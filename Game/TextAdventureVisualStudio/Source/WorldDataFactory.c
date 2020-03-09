/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.
All content © 2020 DigiPen (USA) Corporation, all rights reserved.
******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}


/* TODO REQUIRED: Build room 0 */
Room* DirtField1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	room = Room_Create("You open your eyes. You are in a large field, which becomes easier to make out as your head clears. You stand up and gaze upon the stretch of grass, noticing lumps of dirt at equal intervals along the land. A fountain catches your eye to the north.");
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "north", 1);
	/* TODO BASIC: Add room exit shortcut for "n" */
	Room_AddRoomExit(room, "n", 1);
	Room_AddRoomExit(room, "to fountain", 1);
	Room_AddRoomExit(room, "to the fountain", 1);
	Room_AddRoomExit(room, "fountain", 1);
	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 1 */
Room* Park2_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("As you walk towards the fountain, you also see a few benches and wilted flowers. Looks like no one has attended to this place in a long time. A dirt path leads to the east down a dark alley and to the west to the subway.");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "east", 2);
	Room_AddRoomExit(room, "west", 5);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to alley", 2);
	Room_AddRoomExit(room, "to the alley", 2);
	Room_AddRoomExit(room, "alley", 2);
	Room_AddRoomExit(room, "to subway", 2);
	Room_AddRoomExit(room, "to the subway", 2);
	Room_AddRoomExit(room, "subway", 2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to field", 0);
	Room_AddRoomExit(room, "to the field", 0);
	Room_AddRoomExit(room, "field", 0);
	Room_AddRoomExit(room, "south", 0);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "s", 0);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Alley3_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room;
	room = Room_Create("You walk into the alley, in which you see trash scattered across the ground. A sledgehammer laying on the ground catches your eye. Do the rest of this thanks");
	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}

Room* GroceryStore4_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* DrugStore5_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* Subway6_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* TimesSquare7_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* Hospital8_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* Lab9_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* SecureArea10_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* Apartment11_Build() /*TODO*/
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("Description");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "direction", -1);
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "to place", -1);
	Room_AddRoomExit(room, "to the place", -1);
	Room_AddRoomExit(room, "place", -1);
	Room_AddRoomExit(room, "to place2", -2);
	Room_AddRoomExit(room, "to the place2", -2);
	Room_AddRoomExit(room, "place2", -2);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "to previous", -3);
	Room_AddRoomExit(room, "to the previous", -3);
	Room_AddRoomExit(room, "previous", -3);
	Room_AddRoomExit(room, "previousdirection", -3);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "pdirection", -3);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 11;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, DirtField1_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */

	/*Park*/
	WorldData_SetRoom(worldData, 1, Park2_Build());

	/*Alley*/
	WorldData_SetRoom(worldData, 2, Alley3_Build());

	/*GroceryStore*/
	WorldData_SetRoom(worldData, 3, GroceryStore4_Build());

	/*DrugStore*/
	WorldData_SetRoom(worldData, 4, DrugStore5_Build());

	/*Subway*/
	WorldData_SetRoom(worldData, 5, Subway6_Build());

	/*TimesSquare*/
	WorldData_SetRoom(worldData, 6, TimesSquare7_Build());

	/*Hospital*/
	WorldData_SetRoom(worldData, 7, Hospital8_Build());

	/*Lab*/
	WorldData_SetRoom(worldData, 8, Lab9_Build());

	/*SecureArea*/
	WorldData_SetRoom(worldData, 9, SecureArea10_Build());

	/*Apartment*/
	WorldData_SetRoom(worldData, 10, Apartment11_Build());

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}