#ifndef OBJMGR_H
#define OBJMGR_H

#include <vector>

#include "gameobj.h"

typedef std::vector<GameObj*>::iterator Gobj_it;

/* Manages all logical objs */
class ObjMgr
{
public:
    ObjMgr();
    ~ObjMgr();

    void AcceptGameObj(GameObj *gobj);
    void RemoveGameObj(GameObj *gobj);
    void Clear();


    void Update();

private:
     std::vector<GameObj*> gobjs;
};

#endif // OBJMGR_H
