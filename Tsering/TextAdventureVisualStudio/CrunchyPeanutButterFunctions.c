/******************************************************************************
filename    CrunchyPeanutButterFunctions.c
author      Tsering Ngoche
DP email    N/A
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "crunchyPeanutButter".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "CrunchyPeanutButterFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "EggFunctions.h" /* Egg_Build */


/* Helper: The action performed when the crunchyPeanutButter is used. */
void CrunchyPeanutButter_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* crunchyPeanutButter; /* The crunchyPeanutButter in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the crunchyPeanutButter out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the crunchyPeanutButter - inform the user of the problem and take no action */
		printf("You must have the Crunchy Peanut Butter before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the Crunchy Peanut Butter here.\n");
		return;
	}

	/* check if the Crunchy Peanut Butter has already been used */
	if (GameFlags_IsInList(gameState->gameFlags, "dogGone"))
	{
		/* the player already used the Crunchy Peanut Butter - inform the user of the problem and take no action */
		printf("You already used the Crunchy Peanut Butter here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the Crunchy Peanut Butter in the player's inventory - it should be there, since we are in the Inventory context */
		crunchyPeanutButter = ItemList_FindItem(gameState->inventory, "crunchyPeanutButter");

		/* Remove the Crunchy Peanut Butter from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, crunchyPeanutButter);

		/* Tell the user what they did */
		printf("You fed the dog Crunchy Peanut Butter...it looks like it will follow you now.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "This is room 5. There is a dog guarding an item. Maybe if you fed it something it would move.\n");

		/* Add an egg to the current room, since the cage has been bashed open 
		*roomItemsPtr = ItemList_Add(*roomItemsPtr, Egg_Build()); */

		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "dogGone");
	}
}

/* Build a "crunchyPeanutButter" object */
Item* CrunchyPeanutButter_Build()
{
	/* Create a "crunchyPeanutButter" item, using the functions defined in this file */
	return Item_Create("crunchyPeanutButter", "<add description>", false, CrunchyPeanutButter_Use, NULL, NULL, NULL, NULL);
}