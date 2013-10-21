#include "gamemgr.h"

GameMgr::GameMgr(ScreenMgr *sm, ObjMgr *om, InputMgr *im)
{
    this->objMgr = om;
    this->screenMgr = sm;
    this->inputMgr = im;
    Reset();
}

GameMgr::~GameMgr()
{

}

bool GameMgr::Init(int width, int height)
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        std::cerr << "Failed to initialize GLFW\n" ;
        return false;
    }

    if (!screenMgr->Init(width, height))
       return false;
    //om->Init();

    glfwEnable( GLFW_STICKY_KEYS );

    return true;
}

void GameMgr::Reset()
{
    totalElapsedTime = 0;
    paused = false;
    this->screenMgr = screenMgr;
    this->objMgr = objMgr;
}

void GameMgr::Run()
{
    totalElapsedTime = 0;
    // TODO: maximize framerate and force logic cycles per seconds (lcps)
    timer.start();
    do
    {
        if(!paused)
        {
            objMgr->Update();
        }

        screenMgr->Render();
        inputMgr->Update();

        // Time & FPS
        double elapsedTime = timer.getElapsedTimeInMilliSec();
        double remainingTime = TARGET_MS - elapsedTime;
        totalElapsedTime += elapsedTime;
        if(remainingTime > 0)
        {
            timer.SleepMilliSec(remainingTime);
            //std::this_thread::sleep_for(std::chrono::milliseconds(remainingTime);
            //Sleep((DWORD)(remainingTime * 0.001));
        }
        timer.start();
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS && glfwGetWindowParam( GLFW_OPENED ) );

}

double GameMgr::getElapsedTime()
{
    return totalElapsedTime;
}
