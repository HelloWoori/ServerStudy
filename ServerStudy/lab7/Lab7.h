#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

namespace lab7
{
    template <typename K, class V>
    std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
    {
        // 두 벡터의 길이가 다르면, 두 벡터의 길이 중 짧은 것만큼만 쌍이 생김
        const unsigned int sizeOfKeys = keys.size();
        const unsigned int sizeOfValues = values.size();
        const unsigned int sizeOfMap = (sizeOfKeys < sizeOfValues) ? sizeOfKeys : sizeOfValues;

        std::map<K, V> m;
        for (unsigned int i = 0; i < sizeOfMap; ++i)
        {
            auto it = m.insert(std::pair<K, V>(keys[i], values[i]));
            /*
            // 참고) https://yonmy.com/archives/9 insert 리턴값의 의미
            if (false == it.second)
            {
                std::cout << "키가 중복됨" << std::endl;
            }
            */
        }

        return m;
    }

    template <typename K, class V>
    std::vector<K> GetKeys(const std::map<K, V>& m)
    {
        std::vector<K> v;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            v.push_back(it->first);
        }

        return v;
    }

    template <typename K, class V>
    std::vector<V> GetValues(const std::map<K, V>& m)
    {
        std::vector<V> v;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            v.push_back(it->second);
        }

        return v;
    }

    template <typename T>
    std::vector<T> Reverse(const std::vector<T>& v)
    {
        std::vector<T> rv;
        for (auto it = v.rbegin(); it != v.rend(); ++it)
        {
            rv.push_back(*it);
        }

        return rv;
    }

    template <typename T>
    std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
    {
        std::vector<T> combined; 
        std::map<T, unsigned int> mapForDuplicate; // [vector의 요소, 인덱스]
        for (unsigned int i = 0; i < v1.size(); ++i)
        {
            auto it = mapForDuplicate.insert(std::pair<T, unsigned int>(v1[i], i));
            if (it.second)
            {
                // 아직 중복된 키 없음
                combined.push_back(v1[i]);
            }
        }

        for (unsigned int i = 0; i < v2.size(); ++i)
        {
            auto it = mapForDuplicate.insert(std::pair<T, unsigned int>(v2[i], i));
            if (it.second)
            {
                // 아직 중복된 키 없음
                combined.push_back(v2[i]);
            }
        }

        return combined;
    }

    template <typename K, class V>
    std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
    {
        std::map<K, V> combined;
        for (auto it = m1.begin(); it != m1.end(); ++it)
        {
            combined.insert(std::pair<K, V>(it->first, it->second));
        }

        for (auto it = m2.begin(); it != m2.end(); ++it)
        {
            combined.insert(std::pair<K, V>(it->first, it->second));
        }

        return combined;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
    {
        for (unsigned int i = 0; i < v.size(); ++i)
        {
            os << v[i];
            
            // 마지막이 아닌 경우만 줄 바꿈
            if (i != v.size() - 1)
            {
                os << ", ";
            }
        }

        return os;
    }

    template <typename K, class V>
    std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
    {
        const unsigned int mapSize = m.size();
        unsigned int size = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            ++size;
            os << "{ " << it->first << ", " << it->second << " }";

            // 마지막이 아닌 경우만 줄바꿈
            if (size != mapSize)
            {
                os << "\n";
            }
        }

        return os;
    }

    void Test()
    {
        std::vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);

        std::vector<char> v2;
        v2.push_back('a');
        v2.push_back('b');
        v2.push_back('c');

        std::vector<int> v3;
        v3.push_back(4);
        v3.push_back(5);
        v3.push_back(6);

        std::map<char, int> m1;
        m1['a'] = 1;
        m1['b'] = 2;
        m1['c'] = 3;

        std::map<char, int> m2;
        m1['d'] = 4;
        m1['e'] = 5;
        m1['f'] = 6;

        std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
        {
            std::map<int, char>::const_iterator it = m.begin();

            assert(it->first == 1);
            assert(it->second == 'a');

            it++;
            assert(it->first == 2);
            assert(it->second == 'b');

            it++;
            assert(it->first == 3);
            assert(it->second == 'c');
        }

        std::vector<char> keys = lab7::GetKeys(m1);
        {
            std::vector<char>::const_iterator it = keys.begin();

            assert(*it == 'a');

            it++;
            assert(*it == 'b');

            it++;
            assert(*it == 'c');

        }

        std::vector<int> values = lab7::GetValues(m1);
        {
            std::vector<int>::const_iterator it = values.begin();

            assert(*it == 1);

            it++;
            assert(*it == 2);

            it++;
            assert(*it == 3);
        }

        std::vector<int> reversedV1 = lab7::Reverse(v1);
        {
            assert(reversedV1[0] == v1[2]);
            assert(reversedV1[1] == v1[1]);
            assert(reversedV1[2] == v1[0]);
        }

        std::vector<int> combinedVector = v1 + v3;
        {
            assert(combinedVector.size() == 6);
            assert(combinedVector[0] == 1);
            assert(combinedVector[1] == 2);
            assert(combinedVector[2] == 3);
            assert(combinedVector[3] == 4);
            assert(combinedVector[4] == 5);
            assert(combinedVector[5] == 6);
        }

        std::map<char, int> combinedMap = m1 + m2;
        {

            std::map<char, int>::const_iterator it = combinedMap.begin();

            assert(combinedMap.size() == 6);

            assert(it->first == 'a');
            assert(it->second == 1);

            it++;
            assert(it->first == 'b');
            assert(it->second == 2);

            it++;
            assert(it->first == 'c');
            assert(it->second == 3);

            it++;
            assert(it->first == 'd');
            assert(it->second == 4);

            it++;
            assert(it->first == 'e');
            assert(it->second == 5);

            it++;
            assert(it->first == 'f');
            assert(it->second == 6);
        }

        std::cout << v1 << std::endl;
        std::cout << m1 << std::endl;
    }
} // namespace lab7