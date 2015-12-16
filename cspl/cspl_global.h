#ifndef CSPL_GLOBAL_H
#define CSPL_GLOBAL_H

#ifdef WINDOWS
    #if defined(CSPL_LIBRARY)
    #  define CSPL_PUBLIC __declspec(dllexport)
    #else
    #  define CSPL_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define CSPL_PUBLIC
    #define DEPRECATED(func) __attribute__ ((deprecated))
#endif

#endif // CSPL_GLOBAL_H
