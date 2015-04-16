#ifndef PETRIWIDGET_GLOBAL_H
#define PETRIWIDGET_GLOBAL_H

//#include <QtCore/qglobal.h>

#ifdef WINDOWS
    #ifdef PETRIWIDGET_LIBRARY
        #define PETRIWIDGET_PUBLIC __declspec(dllexport)
    #else
        #define PETRIWIDGET_PUBLIC __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define PETRIWIDGET_PUBLIC
    #define DEPRECATED(func) func __attribute__ ((deprecated))
#endif

#endif // PETRIWIDGET_GLOBAL_H
