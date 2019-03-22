/******************************************************************************
filename    BreakCommandHandler.h
author      Tsering Ngoche
DP email    N/A
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "break" user command, which calls
an item-specific function on a given item

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "break" command, which removes an item and adds an item */
void HandleBreakCommand(CommandData* command, GameState *gameState, WorldData * worldData);