#ifndef SAVELOADFILE_GLOBAL_H
#define SAVELOADFILE_GLOBAL_H

#ifdef WINDOWS
    #ifdef SAVELOADFILE_LIBRARY
        #define SL_PUBLIC __declspec(dllexport)
    #else
        #define SL_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define SL_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // SAVELOADFILE_GLOBAL_H
