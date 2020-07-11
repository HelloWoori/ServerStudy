#include "PolyLine.h"

#include <memory>
#include <limits>

#include "WooriAssert.h"

namespace lab4
{
    void TestPolyLine()
    {
        PolyLine p1;
        p1.AddPoint(1.4f, 2.7f);
        p1.AddPoint(3.5f, 2.1f);
        p1.AddPoint(5.5f, 5.9f);
        p1.AddPoint(-2.2f, 4.0f);
        p1.AddPoint(4.6f, -1.3f);
        p1.AddPoint(6.0f, 4.5f);

        p1.ShowPointList();

        bool bRemoved = p1.RemovePoint(4);
        WOORI_ASSERT(bRemoved, "");

        p1.ShowPointList();

        Point minP(0.f, 0.f);
        Point maxP(0.f, 0.f);

        p1.TryGetMinBoundingRectangle(&minP, &maxP);

        WOORI_ASSERT(minP.GetX() == -2.2f, "");
        WOORI_ASSERT(minP.GetY() ==  2.1f, "");
        WOORI_ASSERT(maxP.GetX() == 6.0f, "");
        WOORI_ASSERT(maxP.GetY() ==  5.9f, "");

        PolyLine a;
        a.AddPoint(new Point(1, 1));
        a.Copy(p1);
    }

    PolyLine::PolyLine()
        : _pointListSize(0)
    {
        Clear();
    }

    PolyLine::~PolyLine()
    {
        Clear();
    }

    void PolyLine::Copy(const PolyLine& other)
    {
        Clear();

        _pointListSize = other._pointListSize;
        for (unsigned int i = 0; i < _pointListSize; ++i)
        {
            _pointList[i] = new Point(*other._pointList[i]);
        }
    }

    bool PolyLine::AddPoint(float x, float y)
    {
        return AddPoint(new Point(x, y));
    }

    bool PolyLine::AddPoint(const Point* point)
    {
        if (nullptr == point)
        {
            return false;
        }

        if (kMaxListSize == _pointListSize)
        {
            delete point;
            return false;
        }

        _pointList[_pointListSize] = point;
        _pointListSize++;

        return true;
    }

    bool PolyLine::RemovePoint(unsigned int index)
    {
        if (_pointListSize <= index)
        {
            return false;
        }

        WOORI_SAFE_DELETE(_pointList[index]);
        for (unsigned int i = index + 1; i < _pointListSize; ++i)
        {
            _pointList[i - 1] = _pointList[i];
        }
        _pointList[_pointListSize - 1] = nullptr;
        _pointListSize--;

        return true;
    }

    bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
    {
        if (nullptr == outMin || nullptr == outMax)
        {
            return false;
        }

        Point tempMin(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
        Point tempMax(std::numeric_limits<float>::min(), std::numeric_limits<float>::min());
        for(unsigned int i = 0; i < _pointListSize; ++i)
        {
            if (_pointList[i]->GetX() < tempMin.GetX())
            {
                tempMin.SetX(_pointList[i]->GetX());
            }

            if (tempMax.GetX() < _pointList[i]->GetX())
            {
                tempMax.SetX(_pointList[i]->GetX());
            }

            if (_pointList[i]->GetY() < tempMin.GetY())
            {
                tempMin.SetY(_pointList[i]->GetY());
            }

            if (tempMax.GetY() < _pointList[i]->GetY())
            {
                tempMax.SetY(_pointList[i]->GetY());
            }
        }

        if (tempMax.GetX() <= tempMin.GetX() || tempMax.GetY() <= tempMin.GetY())
        {
            return false;
        }

        *outMin = tempMin;
        *outMax = tempMax;

        return true;
    }

    void PolyLine::ShowPointList() const
    {
        for (unsigned int i = 0; i <_pointListSize; ++i)
        {
            _pointList[i]->Print();
        }
    }

    const Point* PolyLine::operator[](unsigned int index) const
    {
        return _pointList[index];
    }

    void PolyLine::Clear()
    {
        for (unsigned int i = 0; i < _pointListSize; ++i)
        {
            WOORI_SAFE_DELETE(_pointList[i]);
        }

        _pointListSize = 0;
        std::memset(_pointList, 0, sizeof(_pointList));
    }
} // namespace lab4