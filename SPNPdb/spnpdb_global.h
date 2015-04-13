#ifndef SPNPDB_GLOBAL_H
#define SPNPDB_GLOBAL_H


#ifdef WINDOWS
    #ifdef SPNPDB_LIBRARY
        #define SPNPDB_PUBLIC __declspec(dllexport)
    #else
        #define SPNPDB_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define SPNPDB_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // SPNPDB_GLOBAL_H
