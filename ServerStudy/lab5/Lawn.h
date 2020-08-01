#pragma once

#include "eGrassType.h"
#include "IFenceable.h"

namespace lab5
{
    class Lawn : public IFenceable
    {
    public:
        Lawn();
        virtual ~Lawn();

        virtual unsigned int GetArea() const = 0;
        virtual unsigned int GetMinimumFencesCount() const = 0;
        virtual unsigned int GetFencePrice(eFenceType fenceType) const = 0;

        unsigned int GetGrassPrice(eGrassType grassType) const;
        unsigned int GetMinimumSodRollsCount() const;

    protected:
        bool _isFenceable;
    };
} // namespace lab5