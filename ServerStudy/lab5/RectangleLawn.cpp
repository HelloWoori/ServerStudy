#include "RectangleLawn.h"

#include <cmath>

#include "BarneyUsefulInfo.h"

lab5::RectangleLawn::RectangleLawn()
    : Lawn(), _widthMeter(0), _heightMeter(0)
{
    _isFenceable = true;
}

lab5::RectangleLawn::RectangleLawn(unsigned int widthMeter, unsigned int heightMeter)
    : Lawn(), _widthMeter(widthMeter), _heightMeter(heightMeter)
{
    _isFenceable = true;
}

unsigned int lab5::RectangleLawn::GetArea() const
{
    const unsigned int area = _widthMeter * _heightMeter;
    return area;
}

unsigned int lab5::RectangleLawn::GetMinimumFencesCount() const
{
    const double widthFencesCount = ceil(_widthMeter / BarneyUsefulInfo::kFenceWidthMeter);
    const double  heightFencesCount = ceil(_heightMeter / BarneyUsefulInfo::kFenceWidthMeter);
    return static_cast<unsigned int>((widthFencesCount + heightFencesCount) * 2);
}

unsigned int lab5::RectangleLawn::GetFencePrice(eFenceType fenceType) const
{
    return GetMinimumFencesCount() * BarneyUsefulInfo::GetFenceTypePriceDollars(fenceType);
}
