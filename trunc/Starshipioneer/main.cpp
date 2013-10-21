// #include <QApplication>
#include <glm/glm.hpp>
using namespace glm;

#include "texturemgr.h"
#include "entitymgr.h"
#include "screenmgr.h"
#include "objmgr.h"
#include "inputmgr.h"
#include "gamemgr.h"

#include "screen.h"

#include "starship.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(res);

    // -- -- main mamager classes -- --
    ScreenMgr screenMgr;
    ObjMgr objMgr;
    InputMgr inputMgr;
    GameMgr gameMgr(&screenMgr, &objMgr, &inputMgr);

    if(!gameMgr.Init(1024, 768))
        return -1;

    TextureMgr textureMgr;
    EntityMgr entityMgr;
    if(!entityMgr.Init(&textureMgr))
        return -1;
    // TODO: load stats to cache or not?

    // -- -- main screen -- --
    Screen mainScene;
    screenMgr.PushScreen(&mainScene);

    // test drawable
    coord coords(512, 384, 0);
    size s(50, 50);
//    mainScene.CreateDrawable(&coords, &s, entityMgr.GetTexture(ENTITY_PINGUIN));

    // test worldobj
    StarShip test1(coord(0, 0, 0), size(20, 20), ENTITY_STARSHIP);
    objMgr.AcceptGameObj(&test1);
    test1.SetRep(mainScene.CreateDrawable(&entityMgr, &test1));


    // -- -- execute -- --
    gameMgr.Run();

    return 1; //app.exec();
}
