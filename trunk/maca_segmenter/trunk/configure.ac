AC_PREREQ(2.59)
AC_INIT(maca_segmenter, 2.5, alejandro.acosta@linguist.jussieu.fr)
AC_CONFIG_AUX_DIR(admin)
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

dnl AA Check programs
AC_PROG_CC
AC_PROG_CXX
AC_PROG_MAKE_SET
AC_CHECK_PROG(SH, sh, yes, no)

dnl AA Check libraries
AC_CHECK_LIB([xerces-c],main,,AC_MSG_ERROR([libxerces-c not found]))

dnl AA Check header files
AC_HEADER_STDC

AC_CONFIG_FILES([
        Makefile
        src/Makefile
        src/scripts/Makefile
        ])

AC_OUTPUT
