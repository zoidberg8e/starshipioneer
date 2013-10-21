#ifndef WORLDOBJ_H
#define WORLDOBJ_H

#include "basics.h"
#include "gameobj.h"
#include "drawable.h"
#include "entitymgr.h"

/* Abscract class which represents all objs which are visible in the game world */
class WorldObj : public GameObj
{
public:
    WorldObj(coord p, size s, entityType t);
    ~WorldObj();

    void SetRep(Drawable *r);
    coord* getPosPtr();
    size* getSizePtr();
    entityType getType();

    void setPos(coord pos);


protected:
    Drawable *rep;
    entityType type;
    coord pos;
    size s;
};

#endif // WORLDOBJ_H
