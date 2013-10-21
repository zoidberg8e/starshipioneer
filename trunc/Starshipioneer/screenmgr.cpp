#include "screenmgr.h"

ScreenMgr::ScreenMgr() //QWidget *p)
    //: QGLWidget(p)
{  
}

ScreenMgr::~ScreenMgr()
{
    Clear();
}

void ScreenMgr::PushScreen(Screen *sc)
{
    scns.push_back(sc);
}

void ScreenMgr::PopScreen()
{
    scns.pop_back();
}

void ScreenMgr::Clear()
{
    scns.clear();
}

bool ScreenMgr::Init(int width, int height)
{
    this->width = width;
    this->height = height;
    //glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x antialiasing
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 2); // We want OpenGL 3.3
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    //glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    // Open a window and create its OpenGL context
    if( !glfwOpenWindow( width, height, 0,0,0,0, 32,0, GLFW_WINDOW ) )
    {
        std::cerr << "Failed to open GLFW window\n";

        glfwTerminate();
        return false;
    }

    // Initialize GLEW
    //glewExperimental=true; // Needed in core profile
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW\n";
        return false;
    }

    glfwSetWindowTitle( "S T A R S H I P I O N E E R" );

    glClearColor(0.5, 0.5, 0.1, 1);
    glEnable(GL_TEXTURE_2D);

    return true;
}

void ScreenMgr::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);

    for(Screen_it it = scns.begin(); it < scns.end(); it++)
    {
        (*it)->Render();
    }

    glfwSwapBuffers();
}

void ScreenMgr::Resize(int width, int height)
{
    throw;
}
