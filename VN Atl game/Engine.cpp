#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height)
{
    return this->render_window.Initialize(this, hInstance, window_title, window_class, width, height);
}

bool Engine::ProcessMessages()
{
    return this->render_window.ProcessMessages();
}

void Engine::Update()
{
    while (!keyboard.CharBufferIsEmpty())
    {
        KeyboardEvent kbe = keyboard.ReadKey();
        unsigned char kc = kbe.GetKeyCode();
        std::string omsg = "";
        if (kbe.isPressed())
        {
            omsg += "key press: ";
        }
        if (kbe.isReleased())
        {
            omsg += "key release: ";
        }
        omsg += kc;
        omsg += "\n";
        OutputDebugStringA(omsg.c_str());
    }
    while (!keyboard.CharBufferIsEmpty())
    {
        unsigned char ch = keyboard.ReadChar();
        std::string omsg = "Char: ";
        omsg += ch;
        omsg += "\n";
        OutputDebugStringA(omsg.c_str());
    }
}
