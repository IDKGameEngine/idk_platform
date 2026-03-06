#include "idk/platform/platform_sdl3.hpp"
#include "idk/gfx/renderer_opengl.hpp"
#include <filesystem>

using namespace idk::core;
using namespace idk::platform;


static bool PlatformSDL3BaseRaii()
{
    std::filesystem::current_path(std::filesystem::path(SDL_GetBasePath()));
    return true;
}


PlatformSDL3::PlatformSDL3(const WindowDesc &windesc)
:   running_(PlatformSDL3BaseRaii()),
    shutdown_(false),
    win_(new WindowSDL3(windesc)),
    ren_(new gfx::RendererOpenGL(win_))
{

}

PlatformSDL3::~PlatformSDL3()
{
    delete ren_;
    delete win_;
}


void PlatformSDL3::update()
{
    ren_->beginFrame();

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_EVENT_QUIT)
        {
            this->shutdown();
        }
    }

    // SDL_PumpEvents();
    // const bool *kbstate = SDL_GetKeyboardState(NULL);
    // if (kbstate[SDL_SCANCODE_A])
    // {
    //     input_.move.x -= 1.0f;
    // }

    ren_->endFrame();


    if (shutdown_)
    {
        running_ = false;
        ren_->onShutdown();
    }
}
