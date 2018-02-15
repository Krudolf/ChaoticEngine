#Directories
SRCDIR	:= src/
HDRDIR	:= include/
LIBDIR  := lib/
INCDIR  := lib/include/
OBJDIR	:= obj/
SUBDIRS := $(OBJDIR) $(OBJDIR)manager

#Files
SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SOURCES:%.cpp=%.o))
BINARY 	:= CE

#Compiler set-up
CC		:= g++
LDFLAGS := -Wl,-rpath=$(LIBDIR)
INCLUDE := -I$(HDRDIR) -I$(INCDIR)OpenGL -I$(INCDIR)glm -I$(INCDIR)
LIBS	:= -L$(LIBDIR) -lGL -lGLEW -lglfw -lassimp

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