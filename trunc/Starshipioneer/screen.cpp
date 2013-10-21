#include "screen.h"

Screen::Screen()
{
}

Screen::~Screen()
{
    drws.Clear();
}

Drawable* Screen::CreateDrawable(coord *pos, size *s, GLuint texId)
{
    Drawable *d = drws.CreateEntity();
    d->SetPos(pos);
    d->SetSize(s);
    d->SetTextureID(texId);
    return d;
}

Drawable* Screen::CreateDrawable(EntityMgr *entityMgr, WorldObj *wo)
{
    return CreateDrawable(wo->getPosPtr(), wo->getSizePtr(), entityMgr->GetTexture(wo->getType()));
}

void Screen::DestroyDrawable(Drawable *d)
{
    drws.DestroyEntitiy(d);
}
void Screen::Clear()
{
    drws.Clear();
}

void Screen::Render()
{
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); // Linear Filtering

    //glPushMatrix();
    // Set the camera
   // glScalef(1.0f, 1.0f, 1.0f);

    for(Factory<Drawable>::T_it it = drws.begin(); it < drws.end(); it++)
    {
        it->Render();
    }

    //glPopMatrix();
}
