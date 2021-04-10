CC = g++ 
CFLAGS = -W -Wall 
LIBS = -lusb-1.0 -l pthread
LDFLAGS = -L/usr/include/GL/ -lglut -lGL -lGLU -lGLEW -L/lib65 -lm -lSDL2 
SRCFILES = $(wildcard *.cpp) 
HFILES = $(wildcard *.h) 
OBJFILES = $(patsubst %.o, Shaders/%.o, Program.o)\
		   $(patsubst %.o, Shapes/%.o, Cube.o)
OBJ = $(wildcard *.o)
SUBDIRS := $(wildcard */)
TARGET = main


all : $(SUBDIRS) objects $(TARGET) 

$(SUBDIRS): 
		$(MAKE) -C $@ 

.PHONY : $(SUBDIRS)

$(TARGET) : $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(OBJ) $(CFLAGS) $(LDFLAGS)

objects : $(SRCFILES) $(HFILES)
	$(CC) -c $(SRCFILES)

clean : 
	rm -rf $(OBJFILES) = $(TARGET)

rmproper : clean 
	rm -rf $(TARGET)
