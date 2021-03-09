
#ifndef ENGINECORE_EXPORT_H
#define ENGINECORE_EXPORT_H

#ifdef ENGINECORE_STATIC_DEFINE
#  define ENGINECORE_EXPORT
#  define ENGINECORE_NO_EXPORT
#else
#  ifndef ENGINECORE_EXPORT
#    ifdef enginecore_EXPORTS
        /* We are building this library */
#      define ENGINECORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ENGINECORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ENGINECORE_NO_EXPORT
#    define ENGINECORE_NO_EXPORT 
#  endif
#endif

#ifndef ENGINECORE_DEPRECATED
#  define ENGINECORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ENGINECORE_DEPRECATED_EXPORT
#  define ENGINECORE_DEPRECATED_EXPORT ENGINECORE_EXPORT ENGINECORE_DEPRECATED
#endif

#ifndef ENGINECORE_DEPRECATED_NO_EXPORT
#  define ENGINECORE_DEPRECATED_NO_EXPORT ENGINECORE_NO_EXPORT ENGINECORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ENGINECORE_NO_DEPRECATED
#    define ENGINECORE_NO_DEPRECATED
#  endif
#endif

#endif /* ENGINECORE_EXPORT_H */
