#include "SquareLawn.h"

lab5::SquareLawn::SquareLawn()
    : RectangleLawn()
{
}

lab5::SquareLawn::SquareLawn(unsigned int width)
    : RectangleLawn(width, width)
{
}