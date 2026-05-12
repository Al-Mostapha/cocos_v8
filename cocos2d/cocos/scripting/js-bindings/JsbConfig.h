#define SE_LOGD(...) do { fprintf(stdout, __VA_ARGS__); fflush(stdout); } while (false)
#define SE_LOGE(...) do { fprintf(stderr, __VA_ARGS__); fflush(stderr); } while (false)