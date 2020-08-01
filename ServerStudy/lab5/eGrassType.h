#pragma once

namespace lab5
{
    enum eGrassType
    {
        BERMUDA,
        BAHIA,
        BENTGRASS,
        PERENNIAL_RYEGRASS,
        ST_AUGUSTINE
    };

    enum class eGrassTypePriceCents
    {
        DEFAULT = 0,
        BERMUDA = 800,
        BAHIA = 500,
        BENTGRASS = 300,
        PERENNIAL_RYEGRASS = 250,
        ST_AUGUSTINE = 450
    };
} // namespace lab5