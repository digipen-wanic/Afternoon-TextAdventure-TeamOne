#include "stdafx.h"
#include "McNoodlesFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"

typedef struct WorldData WorldData;


/* Build a "gold piece" object */
Item* Mcnoodles_Build()
{
	return Item_Create("mcnoodles", "This derelict McNoodles™ restaurant has long been picked dry by scavengers. You're not too disappointed. Even though their noodles are soaked with enough preservative to have an expiration date long past the heat death of the universe, you never liked them anyway. You doubt even a dog would eat them.\n", false, NULL, NULL, NULL, NULL, NULL);
}
