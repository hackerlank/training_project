#ifndef SPNPCLASSES_GLOBAL_H
#define SPNPCLASSES_GLOBAL_H

#ifdef WINDOWS
    #ifdef SPNPCLASSES_LIBRARY
        #define SPNPCLASSES_PUBLIC __declspec(dllexport)
    #else
        #define SPNPCLASSES_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define SPNPCLASSES_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // SPNPCLASSES_GLOBAL_H
