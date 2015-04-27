#ifndef PETRIWIDGET_GLOBAL_H
#define PETRIWIDGET_GLOBAL_H

//#include <QtCore/qglobal.h>

#ifdef WINDOWS
    #ifdef PETRIWIDGET_LIBRARY
        #define PW_PUBLIC __declspec(dllexport)
    #else
        #define PW_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define PW_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // PETRIWIDGET_GLOBAL_H
