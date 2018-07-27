#ifndef Py_PROBE_H
#define Py_PROBE_H
#ifdef __cplusplus
extern "C" {
#endif

#ifdef WITH_DTRACE
#define WITH_PYPROBE
#endif

#ifdef WITH_PYPROBE

/* pydtrace_probes.h, on systems with DTrace, is auto-generated to include
   `PyDTrace_{PROBE}` and `PyDTrace_{PROBE}_ENABLED()` macros for every probe
   defined in pydtrace_provider.d.

   Calling these functions must be guarded by a `PyDTrace_{PROBE}_ENABLED()`
   check to minimize performance impact when probing is off. For example:

       if (PyDTrace_FUNCTION_ENTRY_ENABLED())
           PyDTrace_FUNCTION_ENTRY(f);
*/

#ifdef WITH_DTRACE
#include "pydtrace_probes.h"
#endif /* WITH_DTRACE */

static inline void
PyProbe_LINE(const char *arg0, const char *arg1, int arg2)
{
    (void)arg0;
    (void)arg1;
    (void)arg2;

    if (PyDTrace_LINE_ENABLED()) {
        PyDTrace_LINE(arg0, arg1, arg2);
    }
}

static inline void
PyProbe_FUNCTION_ENTRY(const char *arg0, const char *arg1, int arg2)
{
    (void)arg0;
    (void)arg1;
    (void)arg2;

    if (PyDTrace_FUNCTION_ENTRY_ENABLED()) {
        PyDTrace_FUNCTION_ENTRY(arg0, arg1, arg2);
    }
}

static inline void
PyProbe_FUNCTION_RETURN(const char *arg0, const char *arg1, int arg2)
{
    (void)arg0;
    (void)arg1;
    (void)arg2;

    if (PyDTrace_FUNCTION_RETURN_ENABLED()) {
        PyDTrace_FUNCTION_RETURN(arg0, arg1, arg2);
    }
}

static inline void
PyProbe_GC_START(int arg0)
{
    (void)arg0;

    if (PyDTrace_GC_START_ENABLED()) {
        PyDTrace_GC_START(arg0);
    }
}

static inline void
PyProbe_GC_DONE(long arg0)
{
    (void)arg0;

    if (PyDTrace_GC_DONE_ENABLED()) {
        PyDTrace_GC_DONE(arg0);
    }
}

static inline void
PyProbe_INSTANCE_NEW_START(const char *arg0, const char *arg1)
{
    (void)arg0;

    if (PyDTrace_INSTANCE_NEW_START_ENABLED()) {
        PyDTrace_INSTANCE_NEW_START(arg0, arg1);
    }
}

static inline void
PyProbe_INSTANCE_NEW_DONE(const char *arg0, const char *arg1)
{
    (void)arg0;

    if (PyDTrace_INSTANCE_NEW_DONE_ENABLED()) {
        PyDTrace_INSTANCE_NEW_DONE(arg0, arg1);
    }
}

static inline void
PyProbe_INSTANCE_DELETE_START(const char *arg0, const char *arg1)
{
    (void)arg0;

    if (PyDTrace_INSTANCE_DELETE_START_ENABLED()) {
        PyDTrace_INSTANCE_DELETE_START(arg0, arg1);
    }
}

static inline void
PyProbe_INSTANCE_DELETE_DONE(const char *arg0, int arg1)
{
    (void)arg0;

    if (PyDTrace_INSTANCE_DELETE_DONE_ENABLED()) {
        PyDTrace_INSTANCE_DELETE_DONE(arg0, arg1);
    }
}

static inline void
PyProbe_IMPORT_FIND_LOAD_START(const char *arg0)
{
    (void)arg0;

    if (PyDTrace_IMPORT_FIND_LOAD_START_ENABLED()) {
        PyDTrace_IMPORT_FIND_LOAD_START(arg0);
    }
}

static inline void
PyProbe_IMPORT_FIND_LOAD_DONE(const char *arg0, int arg1)
{
    (void)arg0;
    (void)arg1;

    if (PyDTrace_IMPORT_FIND_LOAD_DONE_ENABLED()) {
        PyDTrace_IMPORT_FIND_LOAD_DONE(arg0, arg1);
    }
}

static inline int PyProbe_LINE_ENABLED(void)
{
    if (PyDTrace_LINE_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_FUNCTION_ENTRY_ENABLED(void)
{
    if (PyDTrace_FUNCTION_ENTRY_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_FUNCTION_RETURN_ENABLED(void)
{
    if (PyDTrace_FUNCTION_RETURN_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_GC_START_ENABLED(void)
{
    if (PyDTrace_GC_START_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_GC_DONE_ENABLED(void)
{
    if (PyDTrace_GC_DONE_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_INSTANCE_NEW_START_ENABLED(void)
{
    if (PyDTrace_INSTANCE_NEW_START_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_INSTANCE_NEW_DONE_ENABLED(void)
{
    if (PyDTrace_INSTANCE_NEW_DONE_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_INSTANCE_DELETE_START_ENABLED(void)
{
    if (PyDTrace_INSTANCE_DELETE_START_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_INSTANCE_DELETE_DONE_ENABLED(void)
{
    if (PyDTrace_INSTANCE_DELETE_DONE_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_IMPORT_FIND_LOAD_START_ENABLED(void)
{
    if (PyDTrace_IMPORT_FIND_LOAD_START_ENABLED()) {
        return 1;
    }

    return 0;
}

static inline int PyProbe_IMPORT_FIND_LOAD_DONE_ENABLED(void)
{
    if (PyDTrace_IMPORT_FIND_LOAD_DONE_ENABLED()) {
        return 1;
    }

    return 0;
}

#else

/* Without probing enabled, compile to nothing. */

#define PyProbe_LINE(arg0, arg1, arg2)
#define PyProbe_FUNCTION_ENTRY(arg0, arg1, arg2)
#define PyProbe_FUNCTION_RETURN(arg0, arg1, arg2)
#define PyProbe_GC_START(arg0)
#define PyProbe_GC_DONE(arg0)
#define PyProbe_INSTANCE_NEW_START(arg0, arg1)
#define PyProbe_INSTANCE_NEW_DONE(arg0, arg1)
#define PyProbe_INSTANCE_DELETE_START(arg0, arg1)
#define PyProbe_INSTANCE_DELETE_DONE(arg0, arg1)
#define PyProbe_IMPORT_FIND_LOAD_START(arg0)
#define PyProbe_IMPORT_FIND_LOAD_DONE(arg0, arg1)

#define PyProbe_LINE_ENABLED()                      (0)
#define PyProbe_FUNCTION_ENTRY_ENABLED()            (0)
#define PyProbe_FUNCTION_RETURN_ENABLED()           (0)
#define PyProbe_GC_START_ENABLED()                  (0)
#define PyProbe_GC_DONE_ENABLED()                   (0)
#define PyProbe_INSTANCE_NEW_START_ENABLED()        (0)
#define PyProbe_INSTANCE_NEW_DONE_ENABLED()         (0)
#define PyProbe_INSTANCE_DELETE_START_ENABLED()     (0)
#define PyProbe_INSTANCE_DELETE_DONE_ENABLED()      (0)
#define PyProbe_IMPORT_FIND_LOAD_START_ENABLED()    (0)
#define PyProbe_IMPORT_FIND_LOAD_DONE_ENABLED()     (0)

#endif /* !WITH_PYPROBE */

#ifdef __cplusplus
}
#endif
#endif /* !Py_PROBE_H */
