#include "TimeSheet.h"

#include <iostream>
#include <numeric>

#include "WooriAssert.h"

namespace lab3
{
    void Test()
    {
        TimeSheet woori("Woori", 5);
        woori.AddTime(4);
        woori.AddTime(7);
        woori.AddTime(6);
        woori.AddTime(5);
        woori.AddTime(1);

        std::cout << "Name: " << woori.GetName() << '\n';
        std::cout << "Time index 2: " << woori.GetTimeEntry(2) << '\n';
        std::cout << "Total Time: " << woori.GetTotalTime() << '\n';
        std::cout << "Average Time: " << woori.GetAverageTime() << '\n';
        std::cout << "Standard Deviation: " << woori.GetStandardDeviation() << '\n';


        TimeSheet hun("", 0);
        std::cout << "Name: " << hun.GetName() << '\n';
        std::cout << "Average Time: " << hun.GetAverageTime() << '\n';
        std::cout << "Standard Deviation: " << hun.GetStandardDeviation() << '\n';
    }

    TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
    {
        _workingTimeInHoursList.reserve(maxEntries);
        SetName(name);
    }

    TimeSheet::~TimeSheet()
    {
        // do nothing
    }

    void TimeSheet::AddTime(const int timeInHours)
    {
        if (false == IsValidTimeInHours(timeInHours))
        {
            return;
        }

        if (false == IsInsertable())
        {
            return;
        }

        _workingTimeInHoursList.push_back(timeInHours);   
    }

    int TimeSheet::GetTimeEntry(const unsigned int index) const
    {
        if (false == HasEntry(index))
        {
            return kInvalidInt;
        }

        return _workingTimeInHoursList[index];
    }

    int TimeSheet::GetTotalTime() const
    {
        int totalTime = 0;
        for (const int workingTimeInHours : _workingTimeInHoursList)
        {
            totalTime += workingTimeInHours;
        }

        return totalTime;
    }

    float TimeSheet::GetAverageTime() const
    {
        if (0 == _workingTimeInHoursList.size())
        {
            // divide by Zero
            return kInvalidFloat;
        }

        return static_cast<float>(GetTotalTime()) / static_cast<float>(_workingTimeInHoursList.size());
    }

    float TimeSheet::GetStandardDeviation() const
    {
        // 표준편차: 편차의 제곱의 평균(분산)의 제곱근
        std::vector<float> squareOfDeviationList;
        GetSquareOfDeviationList(squareOfDeviationList);
            
        if (0 == squareOfDeviationList.size())
        {
            // divide by Zero
            return kInvalidFloat;
        }

        float sumOfFloat = 0.0f;
        for (const float squareOfDeviation : squareOfDeviationList)
        {
            sumOfFloat += squareOfDeviation;
        }

        const float variance = sumOfFloat / static_cast<float>(squareOfDeviationList.size());

        return sqrtf(variance);
    }

    const std::string& TimeSheet::GetName() const
    {
        return _name;
    }

    void TimeSheet::SetName(const char* name)
    {
        if (nullptr == name)
        {
            WOORI_ASSERT(nullptr == name, "name 은 NULL 이 될 수 없음!");
        }
  
        _name = name;
    }

    bool TimeSheet::IsValidTimeInHours(const int timeInHours) const
    {
        if (timeInHours < kMinWorkingTimeInHours || kMaxWorkomgTimeInHours < timeInHours)
        {
            return false;
        }

        return true;
    }

    bool TimeSheet::IsInsertable() const
    {
        if (_workingTimeInHoursList.capacity() <= _workingTimeInHoursList.size())
        {
            return false;
        }

        return true;
    }

    bool TimeSheet::HasEntry(const unsigned int index) const
    {
        if (_workingTimeInHoursList.size() <= index)
        {
            return false;
        }

        return true;
    }

    void TimeSheet::GetSquareOfDeviationList(std::vector<float>& outSquareOfDeviationList) const
    {
        std::vector<float> squareOfDeviationList;
        squareOfDeviationList.reserve(_workingTimeInHoursList.size());

        const float averageTime = GetAverageTime();
        for (const int workingTimeInHours : _workingTimeInHoursList)
        {
            const float deviation = static_cast<float>(workingTimeInHours) - averageTime;
            squareOfDeviationList.push_back(powf(deviation, 2.0f));
        }

        squareOfDeviationList.swap(outSquareOfDeviationList);
    }
} // namespace lab3