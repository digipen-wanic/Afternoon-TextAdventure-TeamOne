/******************************************************************************
filename    CombineCommandHandler.h
author      Tsering Ngoche
DP email    N/A
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "combine" user command, which calls
an item-specific function on a given item

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "combine" command, which removes two items and adds a new item */
void HandleCombineCommand(CommandData* command, GameState *gameState, WorldData *worldData);