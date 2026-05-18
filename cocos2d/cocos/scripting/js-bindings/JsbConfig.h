#define SE_LOGD(...)                  \
    do                                \
    {                                 \
        fprintf(stdout, __VA_ARGS__); \
        fflush(stdout);               \
    } while (false)
#define SE_LOGE(...)                  \
    do                                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    } while (false)
#define SE_REPORT_ERROR(...)          \
    do                                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    } while (false)

#define KEY_PRIVATE_DATA "__cc_private_data"

#define SE_PRECONDITION2(cond, ret, msg) \
    do                                   \
    {                                    \
        if (!(cond))                     \
        {                                \
            SE_REPORT_ERROR(msg);        \
            return (ret);                \
        }                                \
    } while (0)

/** @def SE_DEPRECATED_ATTRIBUTE
 * Only certain compilers support __attribute__((deprecated)).
 */
#if defined(__GNUC__) && ((__GNUC__ >= 4) || ((__GNUC__ == 3) && (__GNUC_MINOR__ >= 1)))
#define SE_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#elif _MSC_VER >= 1400 // vs 2005 or higher
#define SE_DEPRECATED_ATTRIBUTE __declspec(deprecated)
#else
#define SE_DEPRECATED_ATTRIBUTE
#endif // SE_DEPRECATED_ATTRIBUTE
