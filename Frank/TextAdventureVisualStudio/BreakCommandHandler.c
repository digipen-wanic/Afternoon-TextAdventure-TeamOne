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
}
