#ifndef DRAWABLEMGR_H
#define DRAWABLEMGR_H

#include <GL/glew.h>
#include <GL/glfw.h>

#include <vector>
#include <iostream>

#include "timer.h"
#include "screen.h"

class ScreenMgr// : public QGLWidget
{
public:
    ScreenMgr();
    ~ScreenMgr();

    void PushScreen(Screen *sc);
    void PopScreen();
    void Clear();

    bool Init(int width, int height);
    void Render();

    void Resize(int width, int height);

private:
    std::vector<Screen*> scns;
    int width, height;
};

#endif // DRAWABLEMGR_H
