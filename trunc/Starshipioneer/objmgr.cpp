#include "objmgr.h"

#include <vector>

ObjMgr::ObjMgr()
{
}

ObjMgr::~ObjMgr()
{
    Clear();
}

void ObjMgr::AcceptGameObj(GameObj *gobj)
{
    gobjs.push_back(gobj);
}

void ObjMgr::RemoveGameObj(GameObj *gobj)
{
    // TODO: increase performance
    for(Gobj_it it = gobjs.begin(); it < gobjs.end(); it++)
    {
        if(*it == gobj)
        {
            gobjs.erase(it);
            return;
        }
    }
}

void ObjMgr::Clear()
{
    gobjs.clear();
}


void ObjMgr::Update()
{
    for(Gobj_it it = gobjs.begin(); it < gobjs.end(); it++)
    {
        (*it)->Update();
    }
}
