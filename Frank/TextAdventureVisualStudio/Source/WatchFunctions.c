/******************************************************************************
filename    WatchFunctions.c
author      Andrew Yan
DP email    Andrew.Y@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "watch".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "WatchFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */
#include "GlassFunctions.h"
#include "WatchPartFunctions.h"

typedef struct WorldData WorldData;
void Watch_Break(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* watch; /* the watch in the user's inventory */

						/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the glass piece in the user's inventory */
	watch = ItemList_FindItem(gameState->inventory, "watch");

	/* check if both items are in the user's inventory */
	if (watch == NULL)
	{
		/* both items were not found - tell the user about the problem and take no further action */
		printf("You don't have your watch. \n");
		return;
	}
	gameState->inventory = ItemList_Add(gameState->inventory, Glass_Build());
	gameState->inventory = ItemList_Add(gameState->inventory, WatchPart_Build());
	printf("You got glass and a broken watch! \n");
}
/* Build a "Watch" object */
Item* Watch_Build()
{
	/* Create a "Watch" item, using the functions defined in this file */
	return Item_Create("watch", "A small black watch with a leather band wrists on your wrist. \n", true, NULL, NULL, NULL, NULL, Watch_Break);
}
