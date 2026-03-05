#include "idk/platform/window_sdl3.hpp"
#include "libidk/log.hpp"

using namespace idk::platform;


WindowSDL3::WindowSDL3(const core::WindowDesc& desc)
:   mTitle(desc.title),
    mWidth(desc.width),
    mHeight(desc.height),
    mSdlWin(nullptr),
    mGlCtx(nullptr),
    mShouldClose(false)
{
    if (false == SDL_Init(SDL_INIT_VIDEO))
        VLOG_FATAL("{}", SDL_GetError());

    if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE))
        VLOG_ERROR("{}", SDL_GetError());

    if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4))
        VLOG_ERROR("{}", SDL_GetError());

    if (!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5))
        VLOG_ERROR("{}", SDL_GetError());

    if (!SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1))
        VLOG_ERROR("{}", SDL_GetError());

    if (!SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  24))
        VLOG_ERROR("{}", SDL_GetError());

    if (!SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8))
        VLOG_ERROR("{}", SDL_GetError());

    mSdlWin = SDL_CreateWindow(mTitle, mWidth, mHeight, SDL_WINDOW_OPENGL);
    if (mSdlWin == NULL)
        VLOG_FATAL("SDL_CreateWindow: {}", SDL_GetError());

    mGlCtx = SDL_GL_CreateContext(mSdlWin);
    if (mGlCtx == nullptr)
        VLOG_FATAL("SDL_GL_CreateContext: {}", SDL_GetError());

}

WindowSDL3::~WindowSDL3()
{
    SDL_DestroyWindow(mSdlWin);
    SDL_Quit();
}


int WindowSDL3::getWidth() const
{
    return mWidth;
}

int WindowSDL3::getHeight() const
{
    return mHeight;
}

bool WindowSDL3::shouldClose() const
{
    return mShouldClose;
}

void *WindowSDL3::getNativeHandle() const
{
    return mSdlWin;
}

void *WindowSDL3::getGpuContext() const
{
    return mGlCtx;
}

void WindowSDL3::pollEvents()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_EVENT_QUIT)
        {
            mShouldClose = true;
        }
    }
}


