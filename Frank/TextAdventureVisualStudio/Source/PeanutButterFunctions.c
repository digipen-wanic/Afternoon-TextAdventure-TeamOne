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



Item * PeanutButter_build()
{
	return Item_Create("peanutButter", "A small amount of peanut butter.", true, PeanutButter_Use, PeanutButter_Take, NULL,NULL,NULL);
}
