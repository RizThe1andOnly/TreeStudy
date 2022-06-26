CC = g++
CFLAGS = -g -Wall -c
CPPFLAGS = -g -Wall -c

PROJECTDIR = /mnt/c/workspaces/C++_Learning-workspace/Cpp_Trees
BINDIR = $(PROJECTDIR)/bin
INCLUDEDIR = $(PROJECTDIR)/include

# cpp files to convert to object files
SRCDIR = $(PROJECTDIR)/src
SRCFILESRAW =\
	TreeStudy.cpp\
	TreeStructs.cpp\
	TreeCreator.cpp\
	BinaryIntNode.cpp

SRCFILES = $(patsubst %, $(SRCDIR)/%, $(SRCFILESRAW))
OBJS = $(patsubst %.cpp, $(BINDIR)/%.o, $(SRCFILESRAW))
MAINAPPNAME = TreeStudy


all: TreeStudy

TreeStudy : $(OBJS)
	$(CC) $(OBJS) -o $(MAINAPPNAME)

$(OBJS) :
	$(eval GENERATED_SRC_FILES=$(shell ./scripts/getSrcFiles.sh $(PROJECTDIR)))
	$(CC) $(CPPFLAGS) $(GENERATED_SRC_FILES) -I$(INCLUDEDIR)
	mv *.o ./bin


.PHONY: clean
clean:
	rm -f $(PROJECTDIR)/$(MAINAPPNAME)
	rm -f -r ./bin/*

