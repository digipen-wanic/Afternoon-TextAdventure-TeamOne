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



/* Build a "crunchyPeanutButter" object */
Item* CrunchyPeanutButter_Build()
{
	/* Create a "crunchyPeanutButter" item, using the functions defined in this file */
	return Item_Create("crunchyPeanutButter", "<add description>", false, NULL, NULL, NULL, NULL, NULL);
}