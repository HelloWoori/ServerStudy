#include "Lawn.h"

#include <cmath>

#include "BarneyUsefulInfo.h"

namespace lab5
{
    Lawn::Lawn() : _isFenceable (false)
    {
    }

    Lawn::~Lawn()
    {
    }

    unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
    {
        const unsigned int grassPriceCents = BarneyUsefulInfo::GetGrassPriceCents(grassType);
        const float totalCents = static_cast<float>(GetArea() * grassPriceCents);
        const float grassPriceFloat = ceil(totalCents / BarneyUsefulInfo::kUnitCentsToDollars);
        return static_cast<unsigned int>(grassPriceFloat);
    }

    unsigned int Lawn::GetMinimumSodRollsCount() const
    {
        const float rollsCountFloat = ceil(GetArea() / BarneyUsefulInfo::kWidthOfRollGrass);
        return static_cast<unsigned int>(rollsCountFloat);
    }
} // namespace lab5