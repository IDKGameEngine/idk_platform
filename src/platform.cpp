#include "idk/platform/platform.hpp"
#include "idk/platform/platform_sdl3.hpp"


idk::core::IPlatform *idk::platform::createPlatform(const idk::core::WindowDesc &windesc)
{
    return new idk::platform::PlatformSDL3(windesc);
}

