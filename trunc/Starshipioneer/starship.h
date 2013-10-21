#ifndef STARSHIP_H
#define STARSHIP_H

#include "worldobj.h"
#include "basics.h"

class StarShip : public WorldObj
{
public:
    StarShip(coord p, size s, entityType t);

    void Update();

protected:
    coord vel;
};

#endif // STARSHIP_H
