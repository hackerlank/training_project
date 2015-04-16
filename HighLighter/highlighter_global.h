#ifndef HIGHLIGHTER_GLOBAL_H
#define HIGHLIGHTER_GLOBAL_H

#ifdef WINDOWS
    #ifdef HIGHLIGHTER_LIBRARY
        #define HL_PUBLIC __declspec(dllexport)
    #else
        #define HL_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define HL_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // HIGHLIGHTER_GLOBAL_H
