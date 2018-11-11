CXX = g++
CPPFLAGS = -g -Wall

BUILDDIR ?= build
SRCDIR ?= src
INCLUDEDIR ?= include

LIBS = lib/boost_1_68_0/stage/lib/libboost_filesystem-mgw63-mt-d-x32-1_68.a lib/boost_1_68_0/stage/lib/libboost_filesystem-mgw63-mt-x32-1_68.a lib/boost_1_68_0/stage/lib/libboost_system-mgw63-mt-d-x32-1_68.a lib/boost_1_68_0/stage/lib/libboost_system-mgw63-mt-x32-1_68.a 

SRCS := file_finder file NodeFile TempFile matcher main 
OBJS := $(SRCS:%=$(BUILDDIR)/%.o)
INCS := -I $(INCLUDEDIR) 

mainbuild: clean build

build: $(OBJS)
	$(CXX) $(CPPFLAGS) $(INCS) $(OBJS) $(LIBS) -o bin/temperatureFileAdjustor -static

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -I lib/boost_1_68_0 $(INCS) $(CXXFLAGS) -c $< -o $@ 

.PHONY: clean

clean:
	rmdir $(BUILDDIR) /S /Q
	mkdir $(BUILDDIR)
	rmdir bin /S /Q
	mkdir bin
	




