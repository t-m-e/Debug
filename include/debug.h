#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_ENABLE
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>

    #define DEBUG_INFO(fmt, ...) \
        { \
            printf("(%s:%d INFO) ", __FILE__, __LINE__); \
            printf(fmt, ##__VA_ARGS__); \
            printf("\n"); \
        }
    #define DEBUG_WARN(fmt, ...) \
        { \
            printf("(%s:%d WARN) ", __FILE__, __LINE__); \
            printf(fmt, ##__VA_ARGS__); \
            printf("\n"); \
        }
    #define DEBUG_ERR(fmt, ...) \
        { \
            printf("(%s:%d ERR) ", __FILE__, __LINE__); \
            printf(fmt, ##__VA_ARGS__); \
            printf("\n"); \
        }
    #define DEBUG_FATAL(fmt, ...) \
        { \
            printf("(%s:%d FATAL) ", __FILE__, __LINE__); \
            printf(fmt, ##__VA_ARGS__); \
            printf(" | exiting.\n"); \
        }
    #define DEBUG_ABORT(fmt, ...) \
        { \
            printf("(%s:%d ABORT) ", __FILE__, __LINE__); \
            printf(fmt, ##__VA_ARGS__); \
            printf(" | killing process.\n"); \
            kill(getpid(), SIGKILL); \
        }
#else 
    #define DEBUG_INFO(fmt, ...)
    #define DEBUG_WARN(fmt, ...)
    #define DEBUG_ERR(fmt, ...)
    #define DEBUG_FATAL(fmt, ...)
    #define DEBUG_ABORT(fmt, ...) 
#endif

#endif
