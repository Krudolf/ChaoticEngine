#Directories
SRCDIR	:= src/
HDRDIR	:= include/
LIBDIR  := 
OBJDIR	:= obj/
SUBDIRS := $(OBJDIR)

#Files
SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SOURCES:%.cpp=%.o))
BINARY 	:= CE

#Compiler set-up
CC		:= g++
INCLUDE := -I$(HDRDIR)
LIBS	:= 
#Make binary
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS)

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