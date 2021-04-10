CC = g++ 
CFLAGS = -W -Wall 
LIBS = -lusb-1.0 -l pthread
LDFLAGS = -L/usr/include/GL/ -lglut -lGL -lGLU -lGLEW -L/lib64 -lm -lSDL2 
SRCFILES = $(wildcard *.cpp) 
HFILES = $(wildcard *.h) 
OBJFILES = main.o Renderer.o Camera.o 
SUBDIRS := $(wildcard */.)
TARGET = main

.PHONY : all $(SUBDIRS)

all : $(TARGET) 

subdirs: 
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
		done

$(TARGET) : $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(CFLAGS) $(LDFLAGS)

$(OBJFILES) : $(SRCFILES) $(HFILES)
	$(CC) -c $(SRCFILES)

clean : 
	rm -rf $(OBJFILES) = $(TARGET)

rmproper : clean 
	rm -rf $(TARGET)
