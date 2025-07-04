# Copyright (c) Grant Rostig, grantrostig.com, Boost 1.0 license
# Snippet
#CONFIG += c++latest
#CONFIG += c++20

 TEMPLATE = app
 CONFIG += console
#TEMPLATE = lib
#CONFIG += staticlib
 CONFIG -= app_bundle
 CONFIG -= qt
 CONFIG += warn_on
 CONFIG += thread

#TARGET = eigen_playground
# ??CONFIG += QMAKE_CFLAGS_WARN_ON
# ??CONFIG += QMAKE_CXXFLAGS_WARN_ON
# // Compiler to use (comment out to use default one).
#DEFINES =
#QMAKE_LFLAGS += -static  # actually makes a static object.
#CONFIG += static wrong? why?
#QMAKE_CXX = clang++
QMAKE_CXXFLAGS += \
        -std=c++23		    \
        #-std=gnu++23		    \
        -O0 		            \
        -g3 		            \
        #-ggdb 		            \
        #-ggdb3 	            \
        -fconcepts              \
        #-pedantic              \
        #-pedantic-errors       \
        #-fsanitize=undefined #60K link errors possible   \
        -Wall   		        \  # https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
        -Wextra   		        \
        -Weffc++                \
        -Wconversion            \
        -Wsign-conversion       \
        -Wdeprecated-declarations\
        #-Wno-comment 		    \
        #-Wno-uninitialized 	\
        #-Wno-reorder 		    \
        #-Wno-unused-parameter 	\
        #-Wno-unused-variable   \
        #-std=c++17             \
        #-std=gnu++17           \
        #-std=gnu++1z           \
        #-std=c++20             \
        #-std=gnu++20           \
        #-std=c++2a             \
        #-DBOOST_LOG_DYN_LINK   \  		# on compile line not link line.
        #-DBOOST_SYSTEM_NO_DEPRECATED \  	# not sure what it does.

LIBS += \
        -lpthread               \
        -lrt                    \
        -lstdc++_libbacktrace   \
        #-lboost_system         \
        #-lboost_coroutine      \
        #-lssl                  \  #  missing this still: undefined reference to symbol 'd2i_PrivateKey_bio@@OPENSSL_1_1_0  related to: OPENSSL_API_COMPAT
        #-lcrypto \  #  seems to be needed with -lssl

#INCLUDEPATH += $$PWD/../lib_tty
#INCLUDEPATH += $$PWD/.
#DEPENDPATH  += $$PWD/../lib_tty
#SUBDIRS +=
#if (!include(../../config.txt)) {
#	error("Failed to open config.txt")
#}

HEADERS += \
    GumballMachine.h        \
    HasQuarterState.h       \
    NoQuarterState.h        \
    SoldOutState.h          \
    State.h                 \
    \
    boost_headers.h         \
    cpp_headers.h           \
    global_entities.h       \
    gnuplot-iostream.h      \
    KitchenSink.h           \
    math_grostig.h          \
    random_toolkit.h        \
 \#   $$PWD/..h               \ # probably wrong
    we_made_a_sale_state.h

SOURCES += \
    GumballMachine.cpp        \
    gumballMachineTestDrive.cpp \
    HasQuarterState.cpp     \
    NoQuarterState.cpp      \
    SoldOutState.cpp        \
    #iostreams.cpp \
    #global_entities.cpp \
    #random_toolkit.cpp \
 \####################################################
    we_made_a_sale_state.cpp

# // Boost specific defines.
#DEFINES += BOOST_THREAD_VERSION=4
#DEFINES += BOOST_ASIO_DISABLE_STD_ATOMIC=1          # Workaround for GCC-4.6 issues with atomics
#DEFINES += BOOST_ASIO_DISABLE_HANDLER_TYPE_REQUIREMENTS=1 # Workaround for move-only functors support for ASIO
#isEmpty(BOOST_PATH) {
#    # Path to the Boost.
#    #BOOST_PATH = /data/boost_1_63_0/
#    BOOST_PATH = /data/boost/
#    #BOOST_PATH = /home/antoshkka/experiments/boost_1_63_0/
#}
# Paths to boost headers and libraries
# (if you are using Linux and installed Boost from repository you may comment out those lines).
#INCLUDEPATH += $$BOOST_PATH
#QMAKE_RPATHDIR += $$BOOST_PATH/stage/lib

# boost on fedora26 parial list only derived from Unbuntu list
LIBS += \
        -lboost_atomic \
        -lboost_chrono \
        -lboost_context \
        -lboost_coroutine \
        -lboost_date_time \
        -lboost_fiber \
        -lboost_filesystem \
#        -lboost_graph_parallel \
        -lboost_graph \
        -lboost_iostreams \
        -lboost_locale \
        -lboost_log_setup \
        -lboost_log \
        -lboost_math_c99f \
        -lboost_math_c99l \
        -lboost_math_c99 \
        -lboost_math_tr1f \
        -lboost_math_tr1l \
        -lboost_math_tr1 \
#        -lboost_mpi_python-py27 \
#        -lboost_mpi_python-py35 \
#        -lboost_mpi_python \
#        -lboost_mpi \
        -lboost_prg_exec_monitor \
        -lboost_program_options \
#        -lboost_python-py27 \
#        -lboost_python-py35 \
#        -lboost_python \
        -lboost_random \
        -lboost_regex \
        -lboost_serialization \
#        -lboost_signals \
        -lboost_system \
        -lboost_thread \
        -lboost_timer \
        -lboost_type_erasure \
        -lboost_unit_test_framework \
        -lboost_wave \
        -lboost_wserialization

# boost on ubuntu 17.04
#LIBS += \
#        -lboost_atomic \
#        -lboost_chrono \
#        -lboost_context \
#        -lboost_coroutine \
#        -lboost_date_time \
#        -lboost_fiber \
#        -lboost_filesystem \
#        -lboost_graph_parallel \
#        -lboost_graph \
#        -lboost_iostreams \
#        -lboost_locale \
#        -lboost_log_setup \
#        -lboost_log \
#        -lboost_math_c99f \
#        -lboost_math_c99l \
#        -lboost_math_c99 \
#        -lboost_math_tr1f \
#        -lboost_math_tr1l \
#        -lboost_math_tr1 \
#        -lboost_mpi_python-py27 \
#        -lboost_mpi_python-py35 \
#        -lboost_mpi_python \
#        -lboost_mpi \
#        -lboost_prg_exec_monitor \
#        -lboost_program_options \
#        -lboost_python-py27 \
#        -lboost_python-py35 \
#        -lboost_python \
#        -lboost_random \
#        -lboost_regex \
#        -lboost_serialization \
#        -lboost_signals \
#        -lboost_system \
#        -lboost_thread \
#        -lboost_timer \
#        -lboost_type_erasure \
#        -lboost_unit_test_framework \
#        -lboost_wave \
#        -lboost_wserialization

# intersting switch
#!msvc:LIBS += -lboost_program_options

# Disabling some annoing warnings and adding paths to the Boost libraries.
#msvc {
#    QMAKE_LFLAGS += /LIBPATH:$$BOOST_PATH/stage/lib
#    DEFINES += _CRT_SECURE_NO_WARNINGS
#} else {
#    LIBS += -L$$BOOST_PATH/stage/lib
#}

DISTFILES += \
#    ../../bin/mk_src.sh \
#    CMakeLists.cmake \
#    Makefile \
#    Qt/icons/gallery/index.theme \
#    Qt/icons/gallery/20x20/back.png \
#    Qt/icons/gallery/20x20/drawer.png \
#    Qt/icons/gallery/20x20/menu.png \
#    Qt/icons/gallery/20x20@2/back.png \
#    Qt/icons/gallery/20x20@2/drawer.png \
#    Qt/icons/gallery/20x20@2/menu.png \
#    Qt/icons/gallery/20x20@3/back.png \
#    Qt/icons/gallery/20x20@3/drawer.png \
#    Qt/icons/gallery/20x20@3/menu.png \
#    Qt/icons/gallery/20x20@4/back.png \
#    Qt/icons/gallery/20x20@4/drawer.png \
#    Qt/icons/gallery/20x20@4/menu.png \
#    Qt/icons/gallery/index.theme \
#    Qt/icons/gallery/20x20/back.png \
#    Qt/icons/gallery/20x20/drawer.png \
#    Qt/icons/gallery/20x20/menu.png \
#    Qt/icons/gallery/20x20@2/back.png \
#    Qt/icons/gallery/20x20@2/drawer.png \
#    Qt/icons/gallery/20x20@2/menu.png \
#    Qt/icons/gallery/20x20@3/back.png \
#    Qt/icons/gallery/20x20@3/drawer.png \
#    Qt/icons/gallery/20x20@3/menu.png \
#    Qt/icons/gallery/20x20@4/back.png \
#    Qt/icons/gallery/20x20@4/drawer.png \
#    Qt/icons/gallery/20x20@4/menu.png \
#    Qt/images/arrow.png \
#    Qt/images/arrow@2x.png \
#    Qt/images/arrow@3x.png \
#    Qt/images/arrow@4x.png \
#    Qt/images/arrows.png \
#    Qt/images/arrows@2x.png \
#    Qt/images/arrows@3x.png \
#    Qt/images/arrows@4x.png \
#    Qt/images/qt-logo.png \
#    Qt/images/qt-logo@2x.png \
#    Qt/images/qt-logo@3x.png \
#    Qt/images/qt-logo@4x.png \
 \#    README.txt
    CMakeLists.cmake

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

#unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop-Debug/liblib_tty.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/ -llib_tty
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/ -llib_tty
#else:unix: LIBS += -L$$PWD/../build-lib_tty-Desktop-Debug/ -llib_tty

# win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/liblib_tty.a
# else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/liblib_tty.a
# else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/release/lib_tty.lib
# else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/debug/lib_tty.lib
# else:unix: PRE_TARGETDEPS += $$PWD/../build-lib_tty-Desktop_Qt_5_13_1_GCC_64bit-Debug/liblib_tty.a


#mac:{
#INCLUDEPATH += /usr/local/opt/boost/include \
               #/usr/local/opt/eigen/include
#LIBS -= -lboost_log
#LIBS += -L/usr/local/opt/boost/lib/ \
        #-lboost_log-mt
#}

# Flags to set your compiler into C++03/C++11/C++14 mode.
#msvc {
#    # MSVC compilers
#    CPP03FLAG =
#    CPP11FLAG =
#    CPP14FLAG =
#} else {
#    # all other compilers
#    CPP03FLAG = -std=c++03
#    CPP11FLAG = -std=c++0x
#    CPP14FLAG = -std=c++14
#}
