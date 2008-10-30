# Template for configure.ac
# Jose Luis Rivas <ghostbar at gmx.com>

AC_INIT(COPYING)

AM_INIT_AUTOMAKE(checkers44,0.01)

AM_CONFIG_HEADER(config.h)

AC_PROG_CC

AC_PROG_CXX

AC_PROG_LIBTOOL

PKG_CHECK_MODULES(DEPS, [gtkmm-2.4 >= 2.8.0 libglademm-2.4 >= 2.6.6])

AC_OUTPUT(Makefile src/Makefile)
