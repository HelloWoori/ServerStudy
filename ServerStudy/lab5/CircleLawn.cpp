#include "CircleLawn.h"

#include <cmath>

#include "BarneyUsefulInfo.h"

lab5::CircleLawn::CircleLawn()
    : Lawn(), _radius(0)
{
    _isFenceable = false;
}

lab5::CircleLawn::CircleLawn(unsigned int radius)
    : Lawn(), _radius(radius)
{
    _isFenceable = false;
}

unsigned int lab5::CircleLawn::GetArea() const
{
    const double area = ceil(BarneyUsefulInfo::kPI * _radius * _radius);
    return static_cast<unsigned int>(area);
}

unsigned int lab5::CircleLawn::GetMinimumFencesCount() const
{
    return 0;
}

unsigned int lab5::CircleLawn::GetFencePrice(eFenceType fenceType) const
{
    return 0;
}
