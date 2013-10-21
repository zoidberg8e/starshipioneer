#include "texturemgr.h"

TextureMgr::TextureMgr()
{
}


bool TextureMgr::LoadTexture(char* path, GLuint *textureID)
{
    GLuint tex = 0;
    int backWidth, backHeight;
    unsigned char* image = NULL;

    glGenTextures(1, &tex);

    if(tex == 0 || glGetError() != 0)
    {
        std::cerr << "Failed to generate texture, ";
        if(glGetError() == 0)
            std::cerr << "error 0: OpenGL is not initialized" << std::endl;
        else
            std::cerr << "error " << glGetError() << ": " << gluErrorString(glGetError()) << std::endl;
        return false;
    }

    glBindTexture(GL_TEXTURE_2D, tex);

    // Load texures
    /*
    QImage myQImage = QImage(path);
    image = myQImage.bits();
    backWidth = myQImage.width();
    backHeight = myQImage.height();
    //*/

    image = SOIL_load_image(path, &backWidth, &backHeight, 0, SOIL_LOAD_RGBA);
    //*/

    if(image == NULL)
    {
        std::cerr << "Failed to load texture: " << path << std::endl;
        return false;
    }
    std::cout << "Loaded texture: " << path << " of height " << backHeight << " and width " << backWidth << std::endl;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, backWidth, backHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    SOIL_free_image_data(image);

    *textureID = tex;
    return true;

}
