#include "Lab6.h"

#include <limits>
#include <map>
#include <cassert>
#include <iostream>

namespace lab6
{
    void Test()
    {
        std::vector<int> v;
        v.push_back(4);
        v.push_back(3);
        v.push_back(4);
        v.push_back(12);
        v.push_back(7);
        v.push_back(11);

        int sum = Sum(v);
        int max = Max(v);
        int min = Min(v);
        float average = Average(v);
        int numWithMaxOccurence = NumberWithMaxOccurrence(v);

        SortDescending(v);

        assert(sum == 41);
        assert(max == 12);
        assert(min == 3);
        assert(average == 6.83333349f);
        assert(numWithMaxOccurence == 4);

        for (unsigned int i = 0; i < v.size() - 1; ++i)
        {
            assert(v[i] >= v[i + 1]);
        }
    }
    
    int Sum(const std::vector<int>& v)
    {
        int sum = 0;
        for (const int element : v)
        {
            sum += element;
        }
        return sum;
    }

    int Min(const std::vector<int>& v)
    {
        int minElement = std::numeric_limits<int>::max();
        for (const int element : v)
        {
            if (element < minElement)
            {
                minElement = element;
            }
        }
        return minElement;
    }

    int Max(const std::vector<int>& v)
    {
        int maxElement = std::numeric_limits<int>::min();
        for (const int element : v)
        {
            if (maxElement < element)
            {
                maxElement = element;
            }
        }
        return maxElement;
    }

    float Average(const std::vector<int>& v)
    {
        const int sum = Sum(v);
       
        return static_cast<float>(sum) / v.size();
    }

    int NumberWithMaxOccurrence(const std::vector<int>& v)
    {
        if (0 == v.size())
        {
            return 0;
        }

        //  (element, the num of occurrences)
        std::map<int, unsigned int> mapForOccurrence;
        for (const int element : v)
        {
            const std::map<int, unsigned int>::iterator it = mapForOccurrence.find(element);
            if (it != mapForOccurrence.end())
            {
                ++it->second;
            }
            else
            {
                // the num of occurrences 의 초기값은 1
                mapForOccurrence.insert(std::pair<int, unsigned int>(element, 1));
            }
        }

        unsigned int maxOccurrence = std::numeric_limits<unsigned int>::min();
        std::map<int, unsigned int>::iterator iteratorForMaxElement;
        for (std::map<int, unsigned int>::iterator it = mapForOccurrence.begin(); it != mapForOccurrence.end(); ++it)
        {
            if (maxOccurrence < it->second)
            {
                maxOccurrence = it->second;
                iteratorForMaxElement = it;
            }
        }

        return iteratorForMaxElement->first;
    }

    // HACK: 간단한 정렬 알고리즘으로 구현했다. 성능이 중요하다면 더 좋은 정렬 알고리즘을 사용해야한다
    void SortDescending(std::vector<int>& v)
    {
        for (unsigned int i = 0; i < v.size() - 1; ++i)
        {
            for (unsigned int j = 0; j < v.size() - 1 - i; ++j)
            {
                if (v[j] < v[j + 1])
                {
                    int temp = v[j + 1];
                    v[j + 1] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
} // namespace lab6