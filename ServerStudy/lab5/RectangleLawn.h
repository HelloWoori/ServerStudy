#pragma once

#include "Lawn.h"

namespace lab5
{
    class RectangleLawn : public Lawn
    {
    public:
        RectangleLawn();
        RectangleLawn(unsigned int widthMeter, unsigned int heightMeter);

        virtual unsigned int GetArea() const override;
        virtual unsigned int GetMinimumFencesCount() const override;
        virtual unsigned int GetFencePrice(eFenceType fenceType) const override;

    protected:
        unsigned int _widthMeter;
        unsigned int _heightMeter;
    };
} // namespace lab5