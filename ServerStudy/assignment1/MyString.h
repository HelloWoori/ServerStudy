#pragma once

namespace assignment1
{
    void Test();

    class MyString
    {
    public:
        MyString(const char* s);
        MyString(const MyString& other);
        ~MyString();

        unsigned int GetLength() const;
        const char* GetCString() const;
        
        void Append(const char* s);
        void Append(const MyString& s);
        void Append(const MyString& s, unsigned int locToInsert);
        
        MyString operator+(const MyString& other) const;

        int IndexOf(const char* s);
        int LastIndexOf(const char* s);
        void Interleave(const char* s);
        bool RemoveAt(unsigned int i);
        
        void PadLeft(unsigned int totalLength);
        void PadLeft(unsigned int totalLength, const char c);
        void PadRight(unsigned int totalLength);
        void PadRight(unsigned int totalLength, const char c);

        void Reverse();
        
        bool operator==(const MyString& rhs) const;

        void ToLower();
        void ToUpper();

        unsigned int StrLen(const char* str) const;

    private:
        bool IsCapitalLetter(const char c) const;
        bool IsSmallLetter(const char c) const;

    private:
        char* _str;                   // ���ڿ� �����͸� ����Ű�� ������
        unsigned int _strLen;         // ���ڿ� ����
        unsigned int _memoryCapacity; // ���� �Ҵ�� �޸� ������ ũ��
    };
} // namespace assignment1