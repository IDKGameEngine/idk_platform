#include "idk/platform/platform_sdl3.hpp"
#include "idk/gfx/renderer_opengl.hpp"

using namespace idk::core;
using namespace idk::platform;


PlatformSDL3::PlatformSDL3(const WindowDesc &windesc)
:   running_(true),
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

        // if (SDL_GetWindowFromEvent(&e))
        // {
        //     // if (auto *gfx = getService<gfxapi::RenderEngine>())
        //     // {
        //     //     gfx.on
        //     // }
        // }
    }

    ren_->endFrame();
}


// IRenderer *PlatformSDL3::createRenderer(IWindow *win)
// {
//     return new gfx::RendererOpenGL(win);
// }
