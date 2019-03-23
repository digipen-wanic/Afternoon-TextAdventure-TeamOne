/******************************************************************************
filename    DogFunctions.c
author      Andrew Yan
DP email    Andrew.Y@digipen.edu
course      Wanic Programming

Brief Description:
This file defines the functions to create a specific item, the "dog".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "DogFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

/* Helper: The action performed when the brick is taken. */
void Dog_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("The dog seems to continously run around you partly distracting you.\n");
}


/* Helper: The action performed when the brick is used. */
void Dog_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */

			   /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the dog out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the dog - inform the user of the problem and take no action */
		printf("You must have the dog before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 3)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the dog here.\n");
		return;
	}

	/* get the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* get the list of items in the current room */
	roomItemsPtr = Room_GetItemList(room);

	if (roomItemsPtr == NULL)
	{
		return; /* take no action, as something is wrong - we should always have an item list */
	}

	/* Remove the brick from the user's inventory - they won't need it again */
	gameState->inventory = ItemList_Add(gameState->inventory, Dog_Build());

	/* Tell the user what they did */
	printf("The dog runs around the robot and distracts it allowing you to pass.\n");
	Room_AddRoomExit(room, "north", 0);
}


/* Build a "brick" object */
Item* Dog_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("dog", "A large dog", true, Dog_Use, Dog_Take, NULL, NULL, NULL);
}
