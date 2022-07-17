#include "Input.h"

namespace grs
{
    bool Input::IsKeyDown(int keyCode)
    {
        int keyState = glfwGetKey(Game::window, keyCode);
        return keyState == GLFW_PRESS || keyState == GLFW_REPEAT;
    }
    
    bool Input::IsKeyPressed(int keyCode)
    {
        int keyState = glfwGetKey(Game::window, keyCode);
        return keyState == GLFW_PRESS;
    }
    bool Input::IsButtonPressed(int keyCode)
    {
        int keyState = glfwGetMouseButton(Game::window, keyCode);
        return keyState == GLFW_PRESS;
    }
}