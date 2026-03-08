#pragma once

#include "idk/core/platform.hpp"
#include "idk/platform/window_sdl3.hpp"
#include <glm/glm.hpp>

#include <memory>


namespace idk::platform
{
    idk::core::IPlatformPtr create_platform(const idk::core::WindowDesc&);
    class Platform;
}


class idk::platform::Platform: public idk::core::IPlatform
{
private:
    idk::core::IWindowPtr win_;

public:
    Platform(const idk::core::WindowDesc&);
    virtual const idk::core::IWindowPtr &getWindow() final { return win_; }

    virtual void onUpdate() final;
    virtual void onEnable() final;
    virtual void onDisable() final;
    virtual void onRestart() final;
    virtual void onShutdown() final;

};

