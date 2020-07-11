#pragma once
#include <cassert>

#define WOORI_ASSERT(expression, message) assert(expression && message)
#define WOORI_SAFE_DELETE(pointer)  \
    {                               \
        if (nullptr != (pointer))   \
        {                           \
            delete (pointer);       \
            (pointer) = nullptr;    \
        }                           \
    }