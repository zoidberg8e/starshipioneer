#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>
#include <GL/glut.h>
#include <QGLWidget>

//#include <SOIL/SOIL.h>
//#include <iostream>

#include "drawable.h"
#include "factory.h"
#include "worldobj.h"
#include "entitymgr.h"

class Screen;
typedef std::vector<Screen*>::iterator Screen_it;

class Screen
{
public:
    Screen();
    ~Screen();

    Drawable* CreateDrawable(coord *pos, size* s, GLuint texId);
    Drawable* CreateDrawable(EntityMgr *entityMgr, WorldObj *wo);
    void DestroyDrawable(Drawable *d);
    void Clear();

    void Render();
    void Update();
        //void Resize(int w, int h);

private:
    Factory<Drawable> drws;
    int widht, height;
};

#endif // SCENE_H
