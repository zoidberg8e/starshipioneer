#ifndef GAMEOBJ_H
#define GAMEOBJ_H

/* Abstract class for all logical objs in the game */
class GameObj
{
public:
    GameObj();

    virtual void Update() = 0;
};

#endif // GAMEOBJ_H
