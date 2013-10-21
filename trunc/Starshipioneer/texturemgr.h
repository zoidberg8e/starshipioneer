#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <iostream>
#include <SOIL/SOIL.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>


class TextureMgr
{
public:
    TextureMgr();

    bool LoadTexture(char* path, GLuint *textureID);

};

#endif // TEXTUREMANAGER_H
