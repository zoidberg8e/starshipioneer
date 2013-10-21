#ifndef INPUTMGR_H
#define INPUTMGR_H

#include "GL/glfw.h"
#include <vector>

class InputMgr
{
public:
    InputMgr();

    void Init();
    void Update();

    std::vector<int> getPressedKeyCodes();

private:
    void GLFWCALL keyCallbackFct(int key, int action);
    std::vector<int> pressedKeyCodes;
};

#endif // INPUTMGR_H
