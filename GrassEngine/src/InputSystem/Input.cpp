#include "Input.h"

namespace grs
{
    bool Input::IsKeyDown(int keyCode)
    {
        int keyState = glfwGetKey(Game::window, keyCode);
        return keyState == GLFW_PRESS || keyState == GLFW_REPEAT;
    }
}