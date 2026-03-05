#pragma once

#include "idk/core/platform.hpp"

namespace idk::platform
{
    idk::core::IPlatform *createPlatform(const idk::core::WindowDesc&);
}

