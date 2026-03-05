#pragma once

#include "idk/core/window.hpp"
#include <SDL3/SDL.h>

namespace idk::platform
{
    class WindowSDL3;
}


class idk::platform::WindowSDL3: public idk::core::IWindow
{
public:
    WindowSDL3(const core::WindowDesc&);
    ~WindowSDL3();
    virtual int   getWidth() const final;
    virtual int   getHeight() const final;
    virtual bool  shouldClose() const final;
    virtual void *getNativeHandle() const final;
    virtual void *getGpuContext() const final;
    virtual void  pollEvents() final;

private:
    const char *mTitle;
    const int mWidth;
    const int mHeight;
    SDL_Window *mSdlWin;
    SDL_GLContext mGlCtx;
    bool mShouldClose;
};

