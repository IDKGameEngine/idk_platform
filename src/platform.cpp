#include "idk/platform/platform.hpp"
#include "idk/gfx/gfx.hpp"
#include <filesystem>
#include <filesystem>

using namespace idk::core;
using namespace idk::platform;


idk::core::IPlatformPtr idk::platform::create_platform(const idk::core::WindowDesc &desc)
{
    std::filesystem::current_path(std::filesystem::path(SDL_GetBasePath()));
    return std::make_shared<idk::platform::Platform>(desc);
}



Platform::Platform(const idk::core::WindowDesc &windesc)
:   win_(new WindowSDL3(windesc))
{
    VLOG_INFO("platform::Platform Initialized");
}


void Platform::onUpdate()
{
    using srvcmd = idk::core::ServiceCommand;

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_EVENT_QUIT)
        {
            VLOG_INFO("SDL_EVENT_QUIT");
            srvCmdToAll(srvcmd::Shutdown);
        }
    }

    // SDL_PumpEvents();
    // const bool *kbstate = SDL_GetKeyboardState(NULL);
    // if (kbstate[SDL_SCANCODE_A])
    // {
    //     input_.move.x -= 1.0f;
    // }
}


void Platform::onEnable()
{

}


void Platform::onDisable()
{

}


void Platform::onRestart()
{

}


void Platform::onShutdown()
{

}



// static bool PlatformBaseRaii()
// {
//     std::filesystem::current_path(std::filesystem::path(SDL_GetBasePath()));
//     return true;
// }


// Platform::Platform(const WindowDesc &windesc)
// :   okay_(PlatformBaseRaii()),
//     win_(new WindowSDL3(windesc)),
//     ren_(new gfx::RenderEngine(win_))
// {

// }

// Platform::~Platform()
// {
//     delete ren_;
//     delete win_;
// }


// void Platform::update()
// {
//     SDL_Event e;
//     while (SDL_PollEvent(&e))
//     {
//         if (e.type == SDL_EVENT_QUIT)
//         {
//             this->shutdown();
//         }
//     }

//     // SDL_PumpEvents();
//     // const bool *kbstate = SDL_GetKeyboardState(NULL);
//     // if (kbstate[SDL_SCANCODE_A])
//     // {
//     //     input_.move.x -= 1.0f;
//     // }

//     idk::core::ServiceManager::update();
// }
