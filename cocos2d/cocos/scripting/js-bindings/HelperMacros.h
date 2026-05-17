#pragma once

// Assertion-style precondition check; returns void on failure
#define JSB_PRECONDITION(condition, ...)           \
    do                                             \
    {                                              \
        if (!(condition))                          \
        {                                          \
            fprintf(stderr, "[JSB] " __VA_ARGS__); \
            fprintf(stderr, "\n");                 \
            return;                                \
        }                                          \
    } while (0)

// Precondition check with explicit return value
#define JSB_PRECONDITION2(condition, ret, ...)     \
    do                                             \
    {                                              \
        if (!(condition))                          \
        {                                          \
            fprintf(stderr, "[JSB] " __VA_ARGS__); \
            fprintf(stderr, "\n");                 \
            return (ret);                          \
        }                                          \
    } while (0)


#ifdef __GNUC__
#define SE_UNUSED __attribute__ ((unused))
#else
#define SE_UNUSED
#endif


extern uint32_t __jsbInvocationCount;

