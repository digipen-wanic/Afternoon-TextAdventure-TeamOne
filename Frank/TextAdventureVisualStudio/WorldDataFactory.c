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
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */
#include "CarFunctions.h"
#include "McNoodlesFunctions.h"
#include "CarFunctions.h"
#include "RobotFunctions.h"
#include "PlaygroundFunctions.h"
#include "PeanutButterFunctions.h"
#include "CrunchyPeanutButterFunctions.h"
#include "DogFunctions.h"



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
Room* Room0_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	room = Room_Create("");

	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	/* TODO BASIC: Add room exit shortcut for "n" */

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */

	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 1 */
Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */
	room = Room_Create("The building is completely empty expept for the vault. \n");
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */
	Room_AddRoomExit(room, "south", 2);
	Room_AddRoomExit(room, "vault", 10);

	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	/* TODO BASIC: Add room exit shortcut for "s" */

	/* TODO REQUIRED: Add a brick to the list of items in the room */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You come up to a park, its broken and run down. you also notice a broken playground. You feel slightly depressed. \n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	Room_AddRoomExit(room, "south", 5);
	Room_AddRoomExit(room, "east", 3);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), PlayGround_Build());
	/* return the new room */
	return room;
}


/* TODO ADVANCED: Build room 3 */
/* TODO ADVANCED: Build room 4 */

Room* Room3_Build()
{
	Room* room = NULL;

	room = Room_Create("Scanning the area, a lone robot guards a room heading North. No one's getting past it's watchful eye. Whatever it's guarding must be important. \n");

	Room_AddRoomExit(room, "south", 5);
	Room_AddRoomExit(room, "east", 3);
	Room_AddRoomExit(room, "west", 1);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	ItemList_AddItem(Room_GetItemList(room), Robot_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	
	/* return the new room */
	return room;
}
Room* Room4_Build()
{
	Room* room = NULL;

	room = Room_Create("you come up to a broken down house, there is an old couch, but it doesnt look too comfy. \n");

	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	Room_AddRoomExit(room, "south", 6);
	Room_AddRoomExit(room, "west", 2);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}Room* Room5_Build()
{
	Room* room = NULL;

	room = Room_Create("You see a rundown house with a dog sitting before it.\n");

	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExit(room, "east", 5);
	Room_AddRoomExit(room, "south", 7);

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Dog_Build());

	/* return the new room */
	return room;
}

Room* Room6_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("You see the remains of an old asphalt road. A ruined car is parked on the curb.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 2);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "east", 6);
	Room_AddRoomExit(room, "west", 4);
	Room_AddRoomExit(room, "south", 8);

	/* Items add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Car_Build());

	/* Return the new room */
	return room;
}

Room* Room7_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("There's a McNoodles™ restauraunt built here. And just when you got their stupid jingle out of your head...\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 3);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "west", 5);
	Room_AddRoomExit(room, "south", 9);

	/* Items add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Mcnoodles_Build());

	/* Return the new room */
	return room;
}
Room* Room8_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("You see a trail of dog poo leading north. Not much else here...\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 4);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "east", 8);

	/* Items add items to the room
	ItemList_AddItem(Room_GetItemList(room), Car_Build()); */

	/* Return the new room */
	return room;
}
Room* Room9_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	include an initial room description */
	room = Room_Create("There's a shady guy who looks like he's selling some powdered candy. Too bad you don't have any money...\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 5);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "east", 9);
	Room_AddRoomExit(room, "west", 7);

	/* Items add items to the room
	ItemList_AddItem(Room_GetItemList(room), Car_Build()); */

	/* Return the new room */
	return room;
}
/* This room was done by Andrew */
Room* Room10_Build()
{
	Room* room = NULL;

	room = Room_Create("You are in an old pet store and you can only see a singular jar of peanut butter on a shelf\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 6);
	Room_AddRoomExit(room, "west", 8);

	/* Items add items to the room */
	ItemList_AddItem(Room_GetItemList(room), PeanutButter_build());

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
	worldData = WorldData_Create("Welcome to Team One's GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	
	/* TODO ADVANCED: add additional advanced rooms */

	WorldData_SetRoom(worldData, 0, Room1_Build());
	WorldData_SetRoom(worldData, 1, Room2_Build());
	WorldData_SetRoom(worldData, 2, Room3_Build());
	WorldData_SetRoom(worldData, 3, Room4_Build());
	WorldData_SetRoom(worldData, 4, Room5_Build());
	WorldData_SetRoom(worldData, 5, Room6_Build());
	WorldData_SetRoom(worldData, 6, Room7_Build());
	WorldData_SetRoom(worldData, 7, Room8_Build());
	WorldData_SetRoom(worldData, 8, Room9_Build());
	WorldData_SetRoom(worldData, 9, Room10_Build());
	WorldData_SetRoom(worldData, 10, Room0_Build());
	/* return the new object */
	return worldData;
}