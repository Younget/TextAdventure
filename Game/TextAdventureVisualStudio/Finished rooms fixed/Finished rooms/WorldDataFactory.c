/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */



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
Room* DirtField_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the dirt field description: */
	Room_Create("You open your eyes. You are in a large field, which becomes easier to make out as your head clears. You stand up and gaze upon the stretch of grass, noticing lumps of dirt at equal intervals along the land. A fountain catches your eye to the north.");
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "north", 1);
	/* TODO BASIC: Add room exit shortcut for "n" */
	Room_AddRoomExit(room, 'n', 1);
	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	
	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 1 */
Room* Park_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the park description: */
	Room_Create("As you walk towards the fountain, you also see a few benches and wilted flowers. Looks like no one has attended to this place in a long time. A dirt path leads to the east down a dark alley and to the west to the subway.");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "west", 2);
	Room_AddRoomExit(room, "east", 5);
	Room_AddRoomExit(room, "w", 2);
	Room_AddRoomExit(room, "e", 5);
	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	Room_AddRoomExit(room, "south", 0);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "s", 0);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Newspaper_Build());
	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Alley_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room;
	/* TODO REQUIRED: Call Room_Create with the alley description: */
	Room_Create("You walk into the alley. There is a grocery store to the west and a drugstore to the north");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "east", 1);
	Room_AddRoomExit(room, "west", 3);
	Room_AddRoomExit(room, "north", 4);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	Room_AddRoomExit(room, "e", 1);
	Room_AddRoomExit(room, "w", 3);
	Room_AddRoomExit(room, "n", 4);

	ItemList_AddItem(Room_GetItemList(room), DrugStoreDoor_Build());
	/* return the new room */
	return room;
}

Room* GroceryStore_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the grocery store description: */
	Room_Create("You walk into the grocery store. There is a rotten apple on the ground. Behind the cashier booth is a sledgehammer.");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "east", 2);
	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "e", 2);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), RottenFood_Build());
	/* return the new room */
	return room;
}

Room* DrugStore_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the drugstore description: */
	Room_Create("You enter the drugstore. It look like no one has been here in ages. A ticket on the ground catches your eyes.");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	Room_AddRoomExit(room, "south", 2);

	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "s", 2);
	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Ticket_Build());
	/* return the new room */
	return room;
}

Room* Subway_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the subway description: */
	Room_Create("You walk into the subway station. A ticket booth is in front of you.");

	/* TODO REQUIRED: Add directional exits */
	Room_AddRoomExit(room, "north", 6);
	Room_AddRoomExit(room, "east", 10);
	Room_AddRoomExit(room, "west", 1);

	/* TODO BASIC: Add room exit shortcuts */
	Room_AddRoomExit(room, "n", 6);
	Room_AddRoomExit(room, "e", 10);
	Room_AddRoomExit(room, "w", 1);

	/* return the new room */
	return room;
}

Room* TimesSquare_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the times square description: */
	Room_Create("As you walk through Times Square, you notice that most of the billboard screens are off or static. There is a newspaper on a stand nearby. No one else is here. There is a hospital to the west that you've been to before, but when... you can't remember.");
	
	/* TODO REQUIRED: Add directional exits */
	Room_AddRoomExit(room, "west", 7);
	Room_AddRoomExit(room, "south", 5);

	/* TODO BASIC: Add room exit shortcuts */
	Room_AddRoomExit(room, "w", 7);
	Room_AddRoomExit(room, "s", 5);

	/* TODO REQUIRED: Add items to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* return the new room */
	return room;
}

Room* Hospital_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the hospital description: */
	Room_Create("You walk into the hospital. There is a lab coat hanging up on the wall. A piece of paper is on the receptionist's desk. There is also a door on the north wall labeled \"lab\".");

	/* TODO REQUIRED: Add directional exits */
	Room_AddRoomExit(room, "north", 8);
	Room_AddRoomExit(room, "east", 6);

	/* TODO BASIC: Add room exit shortcuts */
	Room_AddRoomExit(room, "n", 8);
	Room_AddRoomExit(room, "e", 6);

	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Prescription_Build());
	ItemList_AddItem(Room_GetItemList(room), LabCoat_Build());

	/* return the new room */
	return room;
}

Room* Lab_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the lab description: */
	Room_Create("You walk into the lab. There is a syringe on the table, and a keycard on a adjacent one. To the east is a door to a secure area that you've been through many times before.");

	/* TODO REQUIRED: Add directional exits */
	Room_AddRoomExit(room, "east", 9);
	Room_AddRoomExit(room, "south", 7);
	
	/* TODO BASIC: Add room exit shortucts */
	Room_AddRoomExit(room, "e", 9);
	Room_AddRoomExit(room, "s", 7);

	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Syringe_Build());
	ItemList_AddItem(Room_GetItemList(room), Keycard_Build());
	/* return the new room */
	return room;
}

Room* SecureArea_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the secure area description: */
	Room_Create("You walk into the secure area. This is your workplace! There is a piece of paper on your desk. There is a door south that lead back to Times Square");

	/* TODO REQUIRED: Add directional exits */
	Room_AddRoomExit(room, "south", 6);
	Room_AddRoomExit(room, "west", 8);

	/* TODO BASIC: Add room exit shortcuts */
	Room_AddRoomExit(room, "s", 6);
	Room_AddRoomExit(room, "w", 8);

	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Password_Build());
	/* return the new room */
	return room;
}

Room* Apartment_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* TODO REQUIRED: Call Room_Create with the apartment description: */
	Room_Create("You walk into your apartment. There is a computer on your desk.");

	/* TODO REQUIRED: Add directional exits */
	Room_AddRoomExit(room, "west", 5);

	/* TODO BASIC: Add room exit shortcuts */
	Room_AddRoomExit(room, "w", 5);

	/* TODO REQUIRED: Add a brick to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Laptop_Build());
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
	worldData = WorldData_Create("Welcome to the Text Adventure!\n\n", roomCount);

	/* build each room and assign them to the world data */

	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 0, DirtField_Build());
	WorldData_SetRoom(worldData, 1, Park_Build());

	/* TODO ADVANCED: add additional advanced rooms */
	WorldData_SetRoom(worldData, 2, Alley_Build());
	WorldData_SetRoom(worldData, 3, GroceryStore_Build());
	WorldData_SetRoom(worldData, 4, Drugstore_Build());
	WorldData_SetRoom(worldData, 5, Subway_Build());
	WorldData_SetRoom(worldData, 6, TimesSquare_Build());
	WorldData_SetRoom(worldData, 7, Hospital_Build());
	WorldData_SetRoom(worldData, 8, Lab_Build());
	WorldData_SetRoom(worldData, 9, SecureArea_Build());
	WorldData_SetRoom(worldData, 10, Apartment_Build());

	/* return the new object */
	return worldData;
}