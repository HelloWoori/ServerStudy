#pragma once

#include "Point.h"

namespace lab4
{
    void TestPolyLine();

    class Point;
    class PolyLine
    {
    public:
        PolyLine();
        PolyLine(const PolyLine& other) = delete;
        PolyLine& operator=(const PolyLine& other) = delete;
        ~PolyLine();

        void Copy(const PolyLine& other);

        bool AddPoint(float x, float y);
        bool AddPoint(const Point* point);
        bool RemovePoint(unsigned int index);

        bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;
        void ShowPointList() const;

        const Point* operator[](unsigned int index) const;
    
    private:
        void Clear();

    private:
        static const unsigned int kMaxListSize = 10;

        unsigned int _pointListSize;
        const Point* _pointList[kMaxListSize];
    };
} // namespace lab4