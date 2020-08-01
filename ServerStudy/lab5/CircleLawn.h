#pragma once

#include "Lawn.h"

namespace lab5
{
    class CircleLawn : public Lawn
    {
    public:
        CircleLawn();
        CircleLawn(unsigned int radius);

        virtual unsigned int GetArea() const override;
        virtual unsigned int GetMinimumFencesCount() const override;
        virtual unsigned int GetFencePrice(eFenceType fenceType) const override;
    
    private:
        unsigned int _radius;
    };
} // namespace lab5