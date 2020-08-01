#include "MyString.h"

#include <iostream>

#include "WooriAssert.h"
namespace assignment1
{
    void Test()
    {
        MyString s("hello");
        MyString s2("World!");

        s.Append(s2);
        std::cout << s.GetCString() << std::endl;

        //////////////////////////////////////////

        MyString s3("Ahn");
        const char* s4 = "woori";
        s3.Append(s4);
        std::cout << s3.GetCString() << std::endl;

        //////////////////////////////////////////

        std::cout << s3.IndexOf("hn") << std::endl;

        //////////////////////////////////////////

        s3.ToLower();
        std::cout << s3.GetCString() << std::endl;
         
        s3.ToUpper();
        std::cout << s3.GetCString() << std::endl;

        //////////////////////////////////////////

        MyString s5("good");
        MyString s6("morning");
        MyString s7 = s5 + s6;
        std::cout << s7.GetCString() << std::endl;

        //////////////////////////////////////////
        
        MyString s8("hello");
        s8.Reverse();
        std::cout << s8.GetCString() << std::endl;

        //////////////////////////////////////////

        MyString s9("hello");
        MyString s10("hello");
        if (s9 == s10)
        {
            std::cout << "same!" << std::endl;
        }
        else
        {
            std::cout << "not same!" << std::endl;
        }

        //////////////////////////////////////////

        MyString s11("Hello");
        const char* s12 = " World!";
        s11.Interleave(s12);
        std::cout << s11.GetCString() << std::endl;

        //////////////////////////////////////////

        MyString s13("Hello");
        std::cout << s13.LastIndexOf("This") << std::endl;

        //////////////////////////////////////////

        s13.RemoveAt(0);
        std::cout << s13.GetCString() << std::endl;

        //////////////////////////////////////////

        MyString s14("WOW");
        s14.PadLeft(8);
        std::cout << s14.GetCString() << std::endl;
    }

    MyString::MyString(const char* s)
    { 
        _strLen = StrLen(s);
        _memoryCapacity = _strLen + 1;
        _str = new char[_memoryCapacity];

        for (unsigned int idx = 0; idx < _strLen; ++idx)
        {
            _str[idx] = s[idx];
        }

        _str[_strLen] = '\0';
        
    }
    MyString::MyString(const MyString& other)
    {
        _strLen = other._strLen;
        _memoryCapacity = other._memoryCapacity;
        _str = new char[_memoryCapacity];

        for (unsigned int idx = 0; idx < _strLen; ++idx)
        {
            _str[idx] = other._str[idx];
        }

        _str[_strLen] = '\0';
    }

    MyString::~MyString()
    {
        delete[] _str;
    }

    unsigned int MyString::GetLength() const
    {
        return _strLen;
    }

    const char* MyString::GetCString() const
    {
        return _str;
    }

    void MyString::Append(const char* s)
    {
        MyString other(s);
        Append(other);
    }

    void MyString::Append(const MyString& s)
    {
        Append(s, _strLen);
    }

    void MyString::Append(const MyString& s, unsigned int startInsertIdx)
    {
        const unsigned int minNeedCapacity = _strLen + s._strLen + 1;
        if (_memoryCapacity < minNeedCapacity)
        {
            if (minNeedCapacity < _memoryCapacity * 2)
            {
                _memoryCapacity = _memoryCapacity * 2;
            }
            else
            {
                _memoryCapacity = minNeedCapacity;
            }

            // 새롭게 동적할당해준다
            char* prevStr = _str;
            _str = new char[_memoryCapacity];
            memset(_str, 0, _strLen * sizeof(_str[0]));

            // insert 되는 부분 직전까지 내용을 복사한다
            unsigned int srcStrIdx;
            for (srcStrIdx = 0; srcStrIdx < startInsertIdx; ++srcStrIdx)
            {
                _str[srcStrIdx] = prevStr[srcStrIdx];
            }

            // 새롭게 insert 되는 문자열을 넣는다
            for (unsigned int destStrIdx = 0; destStrIdx < s._strLen; ++destStrIdx)
            {
                _str[srcStrIdx + destStrIdx] = s._str[destStrIdx];
            }

            // 나머지 뒷부분을 복사한다
            for (; srcStrIdx < _strLen; ++srcStrIdx)
            {
                _str[s._strLen + srcStrIdx] = prevStr[srcStrIdx];
            }

            delete[] prevStr;

            _strLen += s._strLen;
            _str[_strLen] = '\0';
        }
        else
        {
            for (unsigned int i = _strLen - 1; startInsertIdx <= i; --i)
            {
                _str[i + s._strLen] = _str[i];
            }

            for (unsigned int i = 0; i < s._strLen; ++i)
            {
                _str[i + startInsertIdx] = s._str[i];
            }

            _strLen += s._strLen;
            _str[_strLen] = '\0';
        }
    }

    MyString MyString::operator+(const MyString& other) const
    {
        MyString tempStr = (*this);
        tempStr.Append(other);
        return tempStr;
    }

    int MyString::IndexOf(const char* s)
    {
        MyString destStr(s);
        if (0 == destStr.GetLength())
        {
            return -1;
        }

        unsigned int srcStrIdx, destStrIdx;
        for (srcStrIdx = 0; srcStrIdx <= _strLen - destStr.GetLength(); ++srcStrIdx)
        {
            for (destStrIdx = 0; destStrIdx < destStr.GetLength(); ++destStrIdx)
            {
                if (_str[srcStrIdx + destStrIdx] != destStr.GetCString()[destStrIdx])
                {
                    break;
                }
            }

            if (destStrIdx == destStr.GetLength())
            {
                return srcStrIdx;
            }
        }

        return -1;
    }

    int MyString::LastIndexOf(const char* s)
    {
        int retVal = 0;

        MyString destStr(s);
        if (0 == destStr.GetLength())
        {
            return -1;
        }

        unsigned int srcStrIdx, destStrIdx;
        for (srcStrIdx = 0; srcStrIdx <= _strLen - destStr.GetLength(); ++srcStrIdx)
        {
            for (destStrIdx = 0; destStrIdx < destStr.GetLength(); ++destStrIdx)
            {
                if (_str[srcStrIdx + destStrIdx] != destStr.GetCString()[destStrIdx])
                {
                    break;
                }
            }

            if (destStrIdx == destStr.GetLength())
            {
                retVal =  srcStrIdx;
                destStrIdx = 0;
            }
        }

        if (0 == retVal)
        {
            return -1;
        }

        return retVal;
    }

    void MyString::Interleave(const char* s)
    {
        const unsigned int destStrLen = StrLen(s);
        const unsigned int minNeedCapacity = _strLen + destStrLen + 1;

        if (minNeedCapacity < _memoryCapacity * 2)
        {
            _memoryCapacity = _memoryCapacity * 2;
        }
        else
        {
            _memoryCapacity = minNeedCapacity;
        }

        // 새롭게 동적할당해준다
        char* prevStr = _str;
        _str = new char[_memoryCapacity];
        memset(_str, 0, _strLen * sizeof(_str[0]));

        // 원래 데이터와 다른 데이터를 번갈아가면서 결합해준다
        unsigned int index = 0;
        unsigned int destStrIdx = 0;
        unsigned int srcStrIdx = 0;
        while(index < _strLen + destStrLen)
        {
            if (destStrIdx < _strLen)
            {
                _str[index] = prevStr[destStrIdx];
                ++destStrIdx;
                ++index;
            }

            if (srcStrIdx < destStrLen)
            {
                _str[index] = s[srcStrIdx];
                srcStrIdx++;
                ++index;
            }
        }

        delete[] prevStr;

        _strLen += destStrLen;
        _str[_strLen] = '\0';
    }

    bool MyString::RemoveAt(unsigned int i)
    {
        if (i < 0 || _strLen < i)
        {
            return false;
        }

        for (unsigned int idx = i; idx < _strLen; ++idx)
        {
            _str[idx] = _str[idx + 1];
        }

        --_strLen;

        return true;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
        PadLeft(totalLength, ' ');
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {
        if (_strLen <= totalLength)
        {
            const unsigned int numOfChar = totalLength - _strLen;
            char* tempCharStr = new char[numOfChar + 1];
            memset(tempCharStr, c, numOfChar * (sizeof tempCharStr[0]));
            tempCharStr[numOfChar] = '\0';

            MyString str(tempCharStr);           
            Append(str, 0);

            delete[] tempCharStr;
        }
    }

    void MyString::PadRight(unsigned int totalLength)
    {
        PadRight(totalLength, ' ');
    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {
        if (_strLen <= totalLength)
        {
            const unsigned int numOfChar = totalLength - _strLen;
            char* tempCharStr = new char[numOfChar + 1];
            memset(tempCharStr, c, numOfChar * (sizeof tempCharStr[0]));
            tempCharStr[numOfChar] = '\0';

            MyString str(tempCharStr);
            Append(str, _strLen);

            delete[] tempCharStr;
        }
    }

    void MyString::Reverse()
    {
        const unsigned int halfIdx = static_cast<unsigned int>(_strLen / 2);
        const unsigned int maxIdx = _strLen - 1;

        unsigned int decreasingIdx = maxIdx;
        for (unsigned int increasingIdx = 0; increasingIdx < halfIdx; ++increasingIdx)
        {
            char temp = _str[increasingIdx];
            _str[increasingIdx] = _str[decreasingIdx];
            _str[decreasingIdx] = temp;

            --decreasingIdx;
        }
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        if (rhs.GetLength() != _strLen)
        {
            return false;
        }

        for (unsigned int idx = 0; idx < _strLen; ++idx)
        {
            if (rhs._str[idx] != _str[idx])
            {
                return false;
            }
        }

        return true;
    }

    void MyString::ToLower()
    {
        for (unsigned int idx = 0; idx < _strLen; ++idx)
        {
            if (true == IsCapitalLetter(_str[idx]))
            {
                _str[idx] += ('a' - 'A');
            }
        }
    }

    void MyString::ToUpper()
    {
        for (unsigned int idx = 0; idx < _strLen; ++idx)
        {
            if (true == IsSmallLetter(_str[idx]))
            {
                _str[idx] += ('A' - 'a');
            }
        }
    }

    unsigned int MyString::StrLen(const char* str) const
    {
        unsigned int len = 0;
        while ('\0' != str[len])
        {
            ++len;
        }

        return len;
    }

    bool MyString::IsCapitalLetter(const char c) const
    {
        if (c >= 'A' && c <= 'Z')
        {
            return true;
        }

        return false;
    }

    bool MyString::IsSmallLetter(const char c) const
    {
        if (c >= 'a' && c < 'z')
        {
            return true;
        }

        return false;
    }
}