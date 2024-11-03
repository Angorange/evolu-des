#pragma once

#include "evo_config.h"

#if EVO_NOASSERT

#   define ASSERT(condition, ...) ((void)0)

#else

namespace evolutic::details
{
    void handleAssertionFailure(const char* condition, const char* file, int line, const char* function, const char* format = nullptr, ...);
}

#   define ASSERT(condition, ...) \
        do { \
            if (!(condition)) \
            { \
                evolutic::details::handleAssertionFailure(#condition, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
            } \
        } while (false)

#endif
    