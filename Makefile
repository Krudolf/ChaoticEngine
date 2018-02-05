#Directories
SRCDIR	:= src/
HDRDIR	:= include/
LIBDIR  := lib/
OBJDIR	:= obj/
SUBDIRS := $(OBJDIR)

#Files
SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SOURCES:%.cpp=%.o))
BINARY 	:= CE

#Compiler set-up
CC		:= g++
LDFLAGS := -Wl,-rpath=$(LIBDIR)OpenGL/lib
INCLUDE := -I$(HDRDIR) -I$(LIBDIR)OpenGL/include
LIBS	:= -L$(LIBDIR)OpenGL/lib -lGL -lGLEW -lglfw

#Make binary
$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(INCLUDE) $(LIBS)

#Make objects
$(OBJDIR)%.o: $(SRCDIR)%.cpp
	make setup
	$(CC) -o $@ -c $^ $(INCLUDE)

#Create object directories
setup:
	mkdir -p $(SUBDIRS)

#Deletes object files
clean:
	rm -R -f $(OBJDIR)
	rm -f CE
	rm -f CE.exe

#Makes binary (previous clean)
cleanc:
	make clean
	make

#Runs after compiling
run:
	make
	./CE

#Cleans, compiles and runs
cleanr:
	make clean
	make
	./CE

#Prints sources, objects and headers lists
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))
	$(info $(INCLUDE))
	$(info $(LIBS))