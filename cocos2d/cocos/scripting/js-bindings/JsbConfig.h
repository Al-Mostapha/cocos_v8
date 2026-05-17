#define SE_LOGD(...) do { fprintf(stdout, __VA_ARGS__); fflush(stdout); } while (false)
#define SE_LOGE(...) do { fprintf(stderr, __VA_ARGS__); fflush(stderr); } while (false)
#define SE_REPORT_ERROR(...) do { fprintf(stderr, __VA_ARGS__); fflush(stderr); } while (false)


#define KEY_PRIVATE_DATA "__cc_private_data"

#define SE_PRECONDITION2(cond, ret, msg) do { \
    if (!(cond)) { \
        SE_REPORT_ERROR(msg); \
        return (ret); \
    } \
} while(0)