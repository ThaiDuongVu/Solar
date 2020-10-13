#pragma once

#include "Core.h"
#include "App.h"

namespace Solar
{
    class SOLAR_CLASS Input
    {
    public:
        static bool IsKeyDown(int key);
        static bool IsKeyUp(int key);
    };
} // namespace Solar
