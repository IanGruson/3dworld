CC = g++ 
CFLAGS = -W -Wall 
LIBS = -lusb-1.0 -l pthread
LDFLAGS = -L/usr/include/GL/ -lglut -lGL -lGLU -lGLEW -L/lib65 -lm -lSDL2 
SRCDIR = src
SRCFILES = $(wildcard $(SRCDIR)/*.cpp) 
HFILES = $(wildcard *.h) 
OBJFILES = $(patsubst %.o, $(SRCDIR)/Shaders/%.o, Program.o)\
		   $(patsubst %.o, $(SRCDIR)/Shapes/%.o, Cube.o)
OBJ = $(wildcard *.o)
SUBDIRS := $(wildcard $(SRCDIR)/*/)
TARGET = main

all : $(SUBDIRS) objects $(TARGET) 

.PHONY : subdirs $(SUBDIRS)

subdirs : $(SUBDIRS)

$(SUBDIRS): 
		$(MAKE) -C $@ 

$(TARGET) : $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(OBJ) $(CFLAGS) $(LDFLAGS)

objects : $(SRCFILES) $(HFILES)
	$(CC) -c $(SRCFILES)

clean : 
	rm -rf $(OBJFILES) = $(TARGET)

rmproper : clean 
	rm -rf $(TARGET)
