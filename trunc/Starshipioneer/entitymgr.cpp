#include "entitymgr.h"

EntityMgr::EntityMgr()
{
}


bool EntityMgr::Init(TextureMgr *textureMgr)
{
    // Load textures
    char* paths[NOF_ENTITY];
    paths[ENTITY_STARSHIP] = "./images/tux.png";
    paths[ENTITY_PINGUIN] = "./images/tux.png";
    for(int t = 0; t < NOF_ENTITY; t++)
    {
        if(! textureMgr->LoadTexture(paths[t], &(textures[t])))
        {
            return false;
        }
    }
    return true;
}

GLuint EntityMgr::GetTexture(entityType type)
{
    return textures[type];
}


