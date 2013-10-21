#include "worldobj.h"

WorldObj::WorldObj(coord p, size s, entityType t)
    : pos(p), s(s), type(t)
{ }

WorldObj::~WorldObj()
{ }

void WorldObj::SetRep(Drawable *r)
{ this->rep = r; }

coord* WorldObj::getPosPtr()
{ return &pos; }

size* WorldObj::getSizePtr()
{ return &s; }

entityType WorldObj::getType()
{ return type; }

void WorldObj::setPos(coord pos)
{ this->pos = pos; }
