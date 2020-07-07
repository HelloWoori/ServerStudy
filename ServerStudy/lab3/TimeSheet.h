/*
    20200704
*/

#pragma once

#include <string>
#include <vector>

namespace lab3
{
    void Test();

    class TimeSheet
    {
    public:
        TimeSheet(const char* name, unsigned int maxEntries);
        ~TimeSheet();

        void AddTime(const int timeInHours);
        int GetTimeEntry(const unsigned int index) const;
        int GetTotalTime() const;
        float GetAverageTime() const;
        float GetStandardDeviation() const;
        const std::string& GetName() const;

    private:
        void SetName(const char* name);
        bool IsValidTimeInHours(const int timeInHours) const;
        bool IsInsertable() const;
        bool HasEntry(const unsigned int index) const;
        void GetSquareOfDeviationList(std::vector<float>& outSquareOfDeviationList) const;

    private:
        const int kMinWorkingTimeInHours = 1;
        const int kMaxWorkomgTimeInHours = 10;

        const float kInvalidFloat = FLT_MAX;
        const int kInvalidInt = -1;

        std::vector<int> _workingTimeInHoursList;
        std::string _name;
    };
} // namespace lab3