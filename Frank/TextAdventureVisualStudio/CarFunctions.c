#include "stdafx.h"
#include "CarFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"

typedef struct WorldData WorldData;


/* Build a "gold piece" object */
Item* Car_Build()
{
	return Item_Create("car", "A fancy, high-end sports car, sadly covered from rust from bumper to bumper. It reminds you of your old car that you'd go outside and spend all day admiring in a voice loud enough for your neighbors to hear. You miss your car.\n", false, NULL, NULL, NULL, NULL, NULL);
}
