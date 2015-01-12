AUTOMAKE_OPTIONS = foreign

ACLOCAL_AMFLAGS = -I m4
LDFLAGS=-L/usr/local/lib -lsqlite3 -lcrypt -lboost_regex -lboost_system -lboost_filesystem

SRCDIR = ./src
SRC = $(wildcard $(SRCDIR)/*.cpp)

#bin_PROGRAMS = getkey
#getkey_SOURCES = getkey.c circ_list.c

AM_CPPFLAGS =-Wl,-rpath -Wl,LIBDIR -Wl,--whole-archive -O3 -fPIC -I/usr/local/include -std=c++11 -I$(top_srcdir)/inc


lib_LTLIBRARIES = libeloniframework.la
libeloniframework_la_SOURCES = src/EloniFramework.cpp src/ConfigurationManager.cpp src/DatabaseManager.cpp src/SecurityManager.cpp src/ShellManager.cpp
libeloniframework_la_CFLAGS = -I$(top_srcdir)/inc
include_HEADERS = inc/Includes.h inc/EloniFramework.h inc/ConfigurationManager.h inc/DatabaseManager.h inc/SecurityManager.h inc/ShellManager.h

#noinst_LIBRARIES = libeloniframework.a
#libeloniframework_a_SOURCES = src/Application.cpp src/ConfigurationManager.cpp src/DatabaseManager.cpp src/SecurityManager.cpp src/ShellManager.cpp
