#include "EquilateralTriangleLawn.h"

#include <math.h>

#include "BarneyUsefulInfo.h"

lab5::EquilateralTriangleLawn::EquilateralTriangleLawn()
    : Lawn(), _widthMeter(0)
{
    _isFenceable = true;
}

lab5::EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int widthMeter)
    : Lawn(), _widthMeter(widthMeter)
{
    _isFenceable = true;
}

unsigned int lab5::EquilateralTriangleLawn::GetArea() const
{
    const double squareOfWidth = static_cast<double>(_widthMeter) * static_cast<double>(_widthMeter);
    const double area = ceil(sqrt(3) / 4 * squareOfWidth);
    return static_cast<unsigned int>(area);
}

unsigned int lab5::EquilateralTriangleLawn::GetMinimumFencesCount() const
{
    const double fencesCount = ceil(_widthMeter / BarneyUsefulInfo::kFenceWidthMeter);
    return static_cast<unsigned int>(fencesCount * 3);
}

unsigned int lab5::EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
{
    return GetMinimumFencesCount() * BarneyUsefulInfo::GetFenceTypePriceDollars(fenceType);
}
