#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(eloniframework, 0.1, yj.iedema@gmail.com)
AC_CONFIG_SRCDIR([src/EloniFrameWork.cpp])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([subdir-objects])
#AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
#AC_PROG_RANLIB
AC_PROG_LIBTOOL
# Checks for libraries.
# FIXME: Replace `main' with a function in `-lboost_filesystem':
AC_CHECK_LIB(boost_filesystem-gcc-mt, main, [], [
	AC_CHECK_LIB(boost_filesystem-mt, main, , [
		AC_CHECK_LIB(boost_filesystem, main, , [
			AC_MSG_ERROR("Linking against boost::filesystem library failed.")
		])
	])
])
# FIXME: Replace `main' with a function in `-lboost_regex':
AC_CHECK_LIB(boost_regex-gcc-mt, main, [], [
	AC_CHECK_LIB(boost_regex-mt, main, [], [
		AC_CHECK_LIB(boost_regex, main, [], [
			AC_MSG_ERROR("Linking against boost::regex library failed.")
		])
	])
])
# FIXME: Replace `main' with a function in `-lboost_system':
AC_CHECK_LIB(boost_system-gcc-mt, main, [], [
	AC_CHECK_LIB(boost_system-mt, main, [], [
		AC_CHECK_LIB(boost_system, main, [], [
			AC_MSG_ERROR("Linking against boost::system library failed.")
		])
	])
])
# FIXME: Replace `main' with a function in `-lcrypt':
AC_CHECK_LIB(crypt, crypt)
# FIXME: Replace `main' with a function in `-lsqlite3':
AC_CHECK_LIB(sqlite3, sqlite3_open)

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([boost/algorithm/string.hpp])
AC_CHECK_HEADERS([sqlite3.h])
AC_CHECK_HEADERS([climits])
AC_CHECK_HEADERS([crypt.h])
AC_CHECK_HEADERS([bitset])
AC_CHECK_HEADERS([boost/filesystem/operations.hpp])
AC_CHECK_HEADERS([boost/filesystem/path.hpp])
AC_CHECK_HEADERS([sys/types.h])
AC_CHECK_HEADERS([pwd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_UID_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
