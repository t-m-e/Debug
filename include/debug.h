#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG_ENABLE
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>

    #define DEBUG_INFO(fmt, ...) \
        { \
            printf("(%s:%d INFO) " fmt "\n", __FILE__, __LINE__  __VA_ARGS__); \
        }
    #define DEBUG_WARN(fmt, ...) \
        { \
            printf("(%s:%d WARN) " fmt "\n", __FILE__, __LINE__  __VA_ARGS__); \
        }
    #define DEBUG_ERR(fmt, ...) \
        { \
            printf("(%s:%d ERR) " fmt "\n", __FILE__, __LINE__  __VA_ARGS__); \
        }
    #define DEBUG_FATAL(fmt, ...) \
        { \
            printf("(%s:%d FATAL) " fmt " | exiting.\n", __FILE__, __LINE__  __VA_ARGS__); \
        }
    #define DEBUG_ABORT(fmt, ...) \
        { \
            printf("(%s:%d ABORT) " fmt " | killing process.\n", __FILE__, __LINE__  __VA_ARGS__); \
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
