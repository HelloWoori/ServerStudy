#include "BarneyUsefulInfo.h"

namespace lab5 
{
    const double BarneyUsefulInfo::kPI = 3.14;
    const double BarneyUsefulInfo::kWidthOfRollGrass = 0.3;
    const double BarneyUsefulInfo::kFenceWidthMeter = 0.25;
    const int BarneyUsefulInfo::kUnitCentsToDollars = 100;

    unsigned int lab5::BarneyUsefulInfo::GetGrassPriceCents(eGrassType grassType)
    {
        eGrassTypePriceCents grassPriceCents = eGrassTypePriceCents::DEFAULT;
        switch (grassType)
        {
        case eGrassType::BERMUDA:
            grassPriceCents = eGrassTypePriceCents::BERMUDA;
            break;

        case eGrassType::BAHIA:
            grassPriceCents = eGrassTypePriceCents::BAHIA;
            break;

        case eGrassType::BENTGRASS:
            grassPriceCents = eGrassTypePriceCents::BENTGRASS;
            break;

        case eGrassType::PERENNIAL_RYEGRASS:
            grassPriceCents = eGrassTypePriceCents::PERENNIAL_RYEGRASS;
            break;

        case eGrassType::ST_AUGUSTINE:
            grassPriceCents = eGrassTypePriceCents::ST_AUGUSTINE;
            break;

        default:
            WOORI_ASSERT(true, "eGrassType is default!");
        }

        return static_cast<unsigned int>(grassPriceCents);
    }

    double lab5::BarneyUsefulInfo::GetFenceTypePriceDollars(eFenceType fenceType)
    {
        eFenceTypePriceDollars fenceTypePriceDollars = eFenceTypePriceDollars::DEFAULT;
        switch (fenceType)
        {
        case eFenceType::RED_CEDAR:
            fenceTypePriceDollars = eFenceTypePriceDollars::RED_CEDAR;
            break;

        case eFenceType::SPRUE:
            fenceTypePriceDollars = eFenceTypePriceDollars::SPRUE;
            break;

        default:
            WOORI_ASSERT(true, "eFenceType is default!");
        }

        return static_cast<unsigned int>(fenceTypePriceDollars) * kFenceWidthMeter;
    }
} // namespace lab5