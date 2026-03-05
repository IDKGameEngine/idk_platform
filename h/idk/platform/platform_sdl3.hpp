#pragma once

#include "idk/core/platform.hpp"
#include "idk/platform/window_sdl3.hpp"


namespace idk::platform
{
    class PlatformSDL3;
}


class idk::platform::PlatformSDL3: public idk::core::IPlatform
{
private:
    bool running_;
    bool shutdown_;
    WindowSDL3 *win_;
    core::IRenderer *ren_;

public:
    PlatformSDL3(const idk::core::WindowDesc&);
    virtual ~PlatformSDL3();
    virtual void update() final;
    virtual void shutdown() final { shutdown_ = true; }
    virtual bool running() final { return running_; }
    virtual core::IWindow *getWindow() final { return win_; }
    // virtual core::IRenderer *getRenderer(core::IWindow*) final;

};
