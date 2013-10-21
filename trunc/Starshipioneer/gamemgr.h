#ifndef GAMEMGR_H
#define GAMEMGR_H

#include <vector>
//#include <chrono>
#include <stdio.h>

#include "screenmgr.h"
#include "objmgr.h"
#include "inputmgr.h"

// duration of a frame in ms
#define TARGET_MS 16.666

/* Manages the game states, handels the scene and the obj manager. */
class GameMgr
{
public:
    GameMgr(ScreenMgr *screenMgr, ObjMgr *objMgr, InputMgr *im);
    ~GameMgr();

    bool Init(int width, int height);
    void Reset();
    void Run();

    double getElapsedTime();


private:
    ScreenMgr *screenMgr;
    ObjMgr *objMgr;
    InputMgr *inputMgr;

    bool paused;
    Timer timer;
    double totalElapsedTime;
};

#endif // GAMEMGR_H
