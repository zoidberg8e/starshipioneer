#include "mainwindow.h"
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QGLWidget(parent)
{
    // initialize
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}


void MainWindow::initializeGL()
{
    glClearColor(0.1, 0.1, 0.1, 1);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_TEXTURE_2D);


    glGenTextures(1, &backTex);
    glBindTexture(GL_TEXTURE_2D, backTex);

    // Load texures
    int backWidth, backHeight;
    unsigned char* image;

/*
    char* texturePath = ":/images/bg1.jpg"; //  "/home/jan/Starshipioneer/bg1.jpg"; //":/images/bg1.jpg";
    QImage myQImage = QImage(":/images/bg1.jpg");
    image = myQImage.bits();
    backWidth = myQImage.width();
    backHeight = myQImage.height();
    //*/


    char* texturePath = "/home/jan/Starshipioneer/bg1.jpg"; //":/images/bg1.jpg";
    image = SOIL_load_image(texturePath, &backWidth, &backHeight, 0, SOIL_LOAD_RGBA);
    //*/

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, backWidth, backHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

    if(image == NULL)
    {
        std::cerr << "Failed to load Texture: " << texturePath << std::endl;
        //return 0;
    }
    std::cout << "Loaded image of height " << backHeight << " and width " << backWidth << std::endl;

  //  SOIL_free_image_data(image);

//    for(int x = 0; x < backWidth; x++)
//    {
//        for(int y = 0; y < backHeight; y++)
//        {
//            std::cout << image[x + y * backWidth] << atoi(" ");
//        }
//        std::cout << std::endl;
//    }
}
void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity;
//    //glViewport(0,0,this->width(),this->height());
//    //glOrtho(0,640,0,480,0,128);

//    glBegin(GL_TRIANGLES);
//        glVertex3f(-0.5, -0.5, 0);
//        glVertex3f( 0.5, -0.5, 0);
//        glVertex3f(   0,  0.5, 0);
//    glEnd();


//    //glColor3f(1, 0.6, 0);
//    glRotatef(0.5, 0, 0, 1);
//    //glutSolidTeapot(0.6);

    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glViewport(0,0,this->width(), this->height());
    //glOrtho(0,640,0,480,0,128);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, backTex);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); // Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); // Linear Filtering

    //glEnable(GL_ALPHA_TEST);
    //glAlphaFunc(GL_GREATER, 0.1);
    glBegin(GL_QUADS);

     glTexCoord2f(0,0);  glVertex3f(-0.5,  0.5, 0);
     glTexCoord2f(0,1);  glVertex3f(-0.5, -0.5, 0);
     glTexCoord2f(1,1);  glVertex3f( 0.5, -0.5, 0);
     glTexCoord2f(1,0);  glVertex3f( 0.5,  0.5, 0);
    glEnd();

}

void MainWindow::resizeGL(int w, int h)
{
}
