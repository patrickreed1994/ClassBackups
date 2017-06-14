#############################################################################
# Makefile for building: car
# Generated by qmake (2.01a) (Qt 4.8.6) on: Sun Jun 14 00:31:50 2015
# Project:  car.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile car.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		physicsengine.cpp \
		ball.cpp \
		vector.cpp \
		car.cpp moc_main.cpp
OBJECTS       = main.o \
		physicsengine.o \
		ball.o \
		vector.o \
		car.o \
		moc_main.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		car.pro
QMAKE_TARGET  = car
DESTDIR       = 
TARGET        = car

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: car.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile car.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile car.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/car1.0.0 || $(MKDIR) .tmp/car1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/car1.0.0/ && $(COPY_FILE) --parents main.h ball.h car.h vector.h physicsengine.h .tmp/car1.0.0/ && $(COPY_FILE) --parents main.cpp physicsengine.cpp ball.cpp vector.cpp car.cpp .tmp/car1.0.0/ && (cd `dirname .tmp/car1.0.0` && $(TAR) car1.0.0.tar car1.0.0 && $(COMPRESS) car1.0.0.tar) && $(MOVE) `dirname .tmp/car1.0.0`/car1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/car1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_main.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_main.cpp
moc_main.cpp: main.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) main.h -o moc_main.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp main.h \
		physicsengine.h \
		ball.h \
		vector.h \
		car.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

physicsengine.o: physicsengine.cpp physicsengine.h \
		ball.h \
		vector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o physicsengine.o physicsengine.cpp

ball.o: ball.cpp ball.h \
		vector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ball.o ball.cpp

vector.o: vector.cpp vector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vector.o vector.cpp

car.o: car.cpp car.h \
		physicsengine.h \
		ball.h \
		vector.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o car.o car.cpp

moc_main.o: moc_main.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_main.o moc_main.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/patrick/Desktop/car/car/ || $(MKDIR) $(INSTALL_ROOT)/home/patrick/Desktop/car/car/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/home/patrick/Desktop/car/car/$(QMAKE_TARGET)"
	-$(STRIP) "$(INSTALL_ROOT)/home/patrick/Desktop/car/car/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/home/patrick/Desktop/car/car/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/home/patrick/Desktop/car/car/ 


install_sources: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/home/patrick/Desktop/car/./ || $(MKDIR) $(INSTALL_ROOT)/home/patrick/Desktop/car/./ 
	-$(INSTALL_FILE) /home/patrick/Desktop/car/main.cpp $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/physicsengine.cpp $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/ball.cpp $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/vector.cpp $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/car.cpp $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/main.h $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/ball.h $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/car.h $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/vector.h $(INSTALL_ROOT)/home/patrick/Desktop/car/./
	-$(INSTALL_FILE) /home/patrick/Desktop/car/physicsengine.h $(INSTALL_ROOT)/home/patrick/Desktop/car/./


uninstall_sources:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./main.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./physicsengine.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./ball.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./vector.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./car.cpp 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./main.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./ball.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./car.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./vector.h 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/home/patrick/Desktop/car/./physicsengine.h
	-$(DEL_DIR) $(INSTALL_ROOT)/home/patrick/Desktop/car/./ 


install:  install_target install_sources  FORCE

uninstall: uninstall_target uninstall_sources   FORCE

FORCE:
