#pragma once

#include "WooriAssert.h"
#include "eGrassType.h"
#include "eFenceType.h"

namespace lab5
{
    class BarneyUsefulInfo
    {
    public:
        static unsigned int GetGrassPriceCents(eGrassType grassType);
        static double GetFenceTypePriceDollars(eFenceType fenceType);
    
    public:
        static const double kPI;
        static const double kWidthOfRollGrass;
        static const double kFenceWidthMeter;
        static const int kUnitCentsToDollars;
      
    };
} // namespace lab5