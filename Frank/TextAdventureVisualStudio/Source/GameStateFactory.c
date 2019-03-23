/******************************************************************************
filename    GameStateFactory.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the GameState factory, which creates the game state objects used
in this game.

******************************************************************************/
#include "GameStateFactory.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_Create */
#include "ItemList.h"
#include "WatchFunctions.h"


/* Create the game state for a new game */
GameState* CreateInitialGameState()
{
	GameState* initialGameState; /* the new GameState object we will return */
	
	/* create an empty GameState object */
	initialGameState = GameState_Create();

	/* the user starts with a score of 0 */
	initialGameState->score = 0;
	initialGameState->inventory = ItemList_Add(initialGameState->inventory, Watch_Build());
	/* the user starts in room 0 */
	initialGameState->currentRoomIndex = 5;

	/* return the new object */
	return initialGameState;
}