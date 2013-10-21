#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>

#include "texturemgr.h"
#include "basics.h"

/* Manages the stats i.e. all values of game objs */
class EntityMgr
{
public:
    EntityMgr();

    bool Init(TextureMgr *EntityMgr);
    GLuint GetTexture(entityType type);

private:
    GLuint textures[NOF_ENTITY];
};

#endif // ENTITYMANAGER_H
