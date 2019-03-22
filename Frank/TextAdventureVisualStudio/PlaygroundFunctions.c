/******************************************************************************
filename    PeanutButterFunctions.c
author     Jacob Pickett

Brief Description: the file to add the playground item

******************************************************************************/


#include "stdafx.h"
#include "PlayGroundFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"

Item * PlayGround_Build()
{
	return Item_Create("PlayGround", "A run down playground, just looking at it makes you feel sad and depressed inside.\n", false, NULL, NULL, NULL, NULL, NULL);
}
