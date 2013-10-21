#include "inputmgr.h"

InputMgr::InputMgr()
{ }

void InputMgr::Init()
{
    //glfwSetKeyCallback(keyCallbackFct);
}

void InputMgr::Update()
{
    pressedKeyCodes.clear();
}

std::vector<int> InputMgr::getPressedKeyCodes()
{
    return pressedKeyCodes;
}

void GLFWCALL InputMgr::keyCallbackFct(int key, int action)
{
    pressedKeyCodes.push_back(key);
}
