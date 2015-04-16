#ifndef SPNPWRAPPER_GLOBAL_H
#define SPNPWRAPPER_GLOBAL_H

#ifdef WINDOWS
    #ifdef SPNPWRAPPER_LIBRARY
        #define SPNPW_PUBLIC __declspec(dllexport)
    #else
        #define SPNPW_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define SPNPW_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // SPNPWRAPPER_GLOBAL_H
