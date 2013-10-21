#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "GL/glew.h"
#include "basics.h"

/* Represents somethin which will be drawn */
class Drawable
{
public:
    /**
     *dont use thisc constructor outside of Screen.CreateDrawable
     */
    Drawable();
    ~Drawable();


    void SetSize(size *s);
    void SetPos(coord *pos);
    void SetTextureID(GLuint id);

    void Render();

protected:
    // this points to the coordinates and size, so they dont have to be updated
    coord *pos;
    size *s;
    GLuint textureID;
};

#endif // DRAWABLE_H
