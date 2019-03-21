/******************************************************************************
filename    WatchPartFunctions.c
author      Frank Bartkus
DP email    frank.bartkus@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "watch part".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "GlassFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;

/* Build a "exit door" object */
Item* WatchPart_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("watch part", "What time is it? Time for you to get a new watch! \n... \nIt's broken... \n", true, NULL, NULL, NULL, NULL, NULL);
}