#ifndef QACCORDION_GLOBAL_H
#define QACCORDION_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef WINDOWS
    #if defined(QACCORDION_LIBRARY)
    #  define QACCORDIONSHARED_EXPORT __declspec(dllexport)
    #else
    #  define QACCORDIONSHARED_EXPORT __declspec(dllimport)
    #endif
    #define DEPRECATED(func) __declspec(deprecated) func
#elif LINUX
    #define QACCORDIONSHARED_EXPORT
    #define DEPRECATED(func) __attribute__ ((deprecated))
#endif

#ifdef __GNUC__
  #define ATTR_UNUSED __attribute__((unused))
#else
  #define ATTR_UNUSED
#endif

#endif // QACCORDION_GLOBAL_H
