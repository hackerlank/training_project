#ifndef XMLPARSER_GLOBAL_H
#define XMLPARSER_GLOBAL_H

#ifdef WINDOWS
    #ifdef XMLPARSER_LIBRARY
        #define XMLPARSER_PUBLIC __declspec(dllexport)
    #else
        #define XMLPARSER_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define XMLPARSER_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // XMLPARSER_GLOBAL_H
