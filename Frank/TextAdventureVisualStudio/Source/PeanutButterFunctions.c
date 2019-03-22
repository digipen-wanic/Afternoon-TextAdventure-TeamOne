/******************************************************************************
filename    PeanutButterFunctions.c
author     Jacob Pickett

Brief Description: the file to add and give functions to the peanutbutter item

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BrickFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "PeanutButterFunctions.h" /* PeanutButter_Build */
#include "CrunchyPeanutButterFunctions.h" /* PeanutButter_Build */


void PeanutButter_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the brick might be used, whenever it is picked up. */
	printf("the peanut butter looks tasty.\n");
}


/* Helper: The action performed when the brick is used. */
void PeanutButter_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	
						/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("you dont have peanut butter.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 5)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("you look at the peanut butter and decide you dont want to eat it.\n");
		return;
	}
	else
	{
		printf("the dog doesnt want crunchy peanutbutter...\n");
	}
}
void PeanutButter_Combine(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* glass; /* the glass  in the user's inventory */
	Item* peanutButter; /* the egg in the user's inventory */

						/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the glass piece in the user's inventory */
	glass = ItemList_FindItem(gameState->inventory, "glass");

	/* find the peanut butter in the user's inventory */
	peanutButter = ItemList_FindItem(gameState->inventory, "peanut butter");

	/* check if both items are in the user's inventory */
	if ((glass == NULL) || (peanutButter == NULL))
	{
		/* both items were not found - tell the user about the problem and take no further action */
		printf("You don't have anything you can combine peanut butter with. \n");
		return;
	}

	ItemList_Remove(gameState->inventory, glass);
	ItemList_Remove(gameState->inventory, peanutButter);
	ItemList_Add(gameState->inventory, CrunchyPeanutButter_Build());
	printf("You got the crunchy peanut butter! \n");
}


Item * PeanutButter_build()
{
	return Item_Create("peanut butter", "A small amount of peanut butter.", true, PeanutButter_Use, PeanutButter_Take, NULL,NULL,NULL);
}
