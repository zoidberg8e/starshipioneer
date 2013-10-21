#include "starship.h"

StarShip::StarShip(coord p, size s, entityType type)
    : WorldObj(p, s, type), vel(0, 0, 0)
{ }


void StarShip::Update()
{
    pos += vel;
    vel += coord(0.01, 0.01, 0);
}
