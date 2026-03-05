#include "idk/platform.hpp"

using namespace idk::platform;


void Platform::start(Platform &plat)
{
    while (plat.running())
    {
        plat.update();
        // player.update();

        // if (kb->keyWasPressed(SDL_SCANCODE_E))
        //     printf("E PRESSED\n");
        // if (kb->keyWasReleased(SDL_SCANCODE_E))
        //     printf("E RELEASED\n");

        // if (ms->mouseWasPressed(iolib::Mouse::Button::LEFT))
        //     printf("Mouse LEFT PRESSED\n");
        // if (ms->mouseWasReleased(iolib::Mouse::Button::LEFT))
        //     printf("Mouse LEFT RELEASED\n");
    }
}



Platform::Platform()
:   running_(true)
{
    
}
    