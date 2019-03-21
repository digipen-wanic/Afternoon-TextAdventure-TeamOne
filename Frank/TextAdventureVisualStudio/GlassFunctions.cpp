/******************************************************************************
filename    GlassFunctions.c
author      Frank Bartkus
DP email    frank.bartkus@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "GlassFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void Glass_Combine(CommandContext context, GameState* gameState, WorldData* worldData)
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
		printf("You don't have anything you can combine glass with. \n");
		return;
	}

	ItemList_Remove(gameState->inventory, glass);
	ItemList_Remove(gameState->inventory, peanutButter);
	ItemList_Add(gameState->inventory, chunkyButter_Build());
	printf("You got the chunky butter! \n");
}


/* Build a "exit door" object */
Item* Glass_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("glass", "It's the chunks of broken glass from your watch. \n", true, NULL, NULL, NULL, Glass_Combine, NULL);
}