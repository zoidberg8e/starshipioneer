#include "drawable.h"

Drawable::Drawable()
{
    pos = NULL;
}

Drawable::~Drawable()
{
}


void Drawable::SetSize(size *s)
{
    this->s = s;
}

void Drawable::SetPos(coord *pos)
{
    this->pos = pos;
}

void Drawable::SetTextureID(GLuint id)
{
    textureID = id;
}

void Drawable::Render()
{
    //glPushMatrix();
    //glTranslatef((*pos).x, (*pos).y, 0);
    glScalef((*s).width, (*s).height, 1);
    glBindTexture(GL_TEXTURE_2D, textureID); // Todo: texture offset

    // TODO: save in vbo like here: http://www.songho.ca/opengl/gl_vbo.html
    glBegin(GL_QUADS);
     glTexCoord2f(0,0);  glVertex3f(-0.5,  0.5, 0);
     glTexCoord2f(0,1);  glVertex3f(-0.5, -0.5, 0);
     glTexCoord2f(1,1);  glVertex3f( 0.5, -0.5, 0);
     glTexCoord2f(1,0);  glVertex3f( 0.5,  0.5, 0);
    glEnd();

    //glPopMatrix();
}
