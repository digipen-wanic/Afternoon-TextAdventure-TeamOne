         /******************************************************************************
filename    BreakCommandHandler.c
author      Tsering Ngoche
DP email    N/A
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "break" user command, which calls
an item-specific function on a given item

******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "BreakCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */


void HandleBreakCommand(CommandData * command, GameState * gameState, WorldData * worldData)
{
	Item* brokenItem; /* The item that is removed from inventory */
	Room* room; /* The room that the item is being added to */
	ItemList** roomItemPtr; /* A pointer to the item-list pointer held by the room */
	ItemFunc dropFunc; /* The function to be called for the given item when it is dropped */

					   /* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters aren't valid */
	}

	/* get the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	/* get the item list from the current room */
	roomItemPtr = Room_GetItemList(room);
	if (roomItemPtr == NULL)
	{
		return; /* take no action if the room has no item list - this should never happen, though */
	}

	/* find the broken item in the player's inventory */
	brokenItem = ItemList_FindItem(gameState->inventory, command->noun);
	if (brokenItem == NULL)
	{
		/* if the item wasn't found, then the player doesn't have it so they can't drop it */
		printf("You do not have a %s.\n", command->noun);
		return;
	}


	/* everything has succeeded, so output the result */
	printf("You have broken the %s.\n", command->noun);

	/* get the "drop" function for this item, if any (it is optional) */
	dropFunc = Item_GetBreakFunc(brokenItem);
	if (dropFunc != NULL)
	{
		/* call the drop function with the Inventory context, since that's where the item was */
		dropFunc(CommandContext_Item_Inventory, gameState, worldData);
	}
	/* remove the item from inventory and assign the inventory pointer back to the game state */
	gameState->inventory = ItemList_Remove(gameState->inventory, brokenItem);
}