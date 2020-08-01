#pragma once

#include "RectangleLawn.h"

namespace lab5
{
    class SquareLawn : public RectangleLawn
    {
    public:
        SquareLawn();
        SquareLawn(unsigned int width);
    };
} // namespace lab5