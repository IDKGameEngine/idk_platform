#pragma once

#include "idk/core/type.hpp"
#include "idk/platform/window_sdl3.hpp"


namespace idk::platform
{
    class Platform;
}


class idk::platform::Platform: public idk::NonCopyable
{
private:
    bool running_;

public:
    static void start(Platform&);

    Platform();
    void update();
    bool running() const { return running_; }
    

};
