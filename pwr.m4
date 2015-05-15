AM_CONDITIONAL(BUILD_SWIG, [test x"$SWIG" = y])
AM_CONDITIONAL(BUILD_DAEMON, [test x"$DAEMON" = y])
AM_CONDITIONAL(BUILD_DEBUG, [test x"$DEBUG" = y])
AM_CONDITIONAL(BUILD_XMLRPC, [test x"$XMLRPC" = y])
AM_CONDITIONAL(BUILD_PIDEV, [test x"$PIDEV" = y])
AM_CONDITIONAL(BUILD_MACOS, [test x"$MACOS" = y])
AM_CONDITIONAL(BUILD_SHARED, [test x"$SHARED" = y])

AU_ALIAS([SWIG_PYTHON], [AX_SWIG_PYTHON])
AC_DEFUN([AX_SWIG_PYTHON],[
        AC_REQUIRE([AX_PROG_SWIG])
        AC_REQUIRE([AX_PYTHON_DEVEL])
        test "x$1" != "xno" || swig_shadow=" -noproxy"
        AC_SUBST([AX_SWIG_PYTHON_OPT],[-python$swig_shadow])
        AC_SUBST([AX_SWIG_PYTHON_CPPFLAGS],[$PYTHON_CPPFLAGS])
])
