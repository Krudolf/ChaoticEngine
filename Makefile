#Directories
SRCDIR	:= src/
HDRDIR	:= include/
LIBDIR  := lib/
INCDIR  := lib/include/
OBJDIR	:= obj/
SUBDIRS := $(OBJDIR) $(OBJDIR)manager $(OBJDIR)fachada

#Files
SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SOURCES:%.cpp=%.o))
BINARY 	:= CE

#Compiler set-up
CC		:= g++
LDFLAGS := -Wl,-rpath=$(LIBDIR)
INCLUDE := -I$(HDRDIR) -I$(INCDIR) -I$(INCDIR)OpenGL -I$(INCDIR)glm -I$(INCDIR)sfml
LIBS	:= -L$(LIBDIR) -lGL -lGLEW -lglfw -lassimp -lsfml-window -lsfml-graphics -lsfml-system
FAST	:= -j4

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
	rm -f $(BINARY)
	rm -f $(BINARY).exe

#Makes binary (previous clean)
cleanc:
	make clean
	make $(FAST)

#Runs after compiling
run:
	make $(FAST)
	./$(BINARY)

#Cleans, compiles and runs
cleanr:
	make clean
	make $(FAST)
	./$(BINARY)

#Compile the program with 4 threads
fast:
	make $(FAST)

#Prints sources, objects and headers lists
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))
	$(info $(INCLUDE))
	$(info $(LIBS))
