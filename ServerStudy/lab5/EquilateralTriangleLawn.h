#pragma once

#include "Lawn.h"

namespace lab5
{
    class EquilateralTriangleLawn : public Lawn
    {
    public:
        EquilateralTriangleLawn();
        EquilateralTriangleLawn(unsigned int widthMeter);

        virtual unsigned int GetArea() const override;
        virtual unsigned int GetMinimumFencesCount() const override;
        virtual unsigned int GetFencePrice(eFenceType fenceType) const override;

    private:
        unsigned int _widthMeter;
    };
} // namespace lab5