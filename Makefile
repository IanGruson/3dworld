CC = g++ 
CFLAGS = -W -Wall 
LIBS = -lusb-1.0 -l pthread
LDFLAGS = -L/usr/include/GL/ -lglut -lGL -lGLU -lGLEW -L/lib64 -lm -lSDL2 
OBJFILES = main.o renderer.o
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(CFLAGS) $(LDFLAGS)

clean : 
	rm -rf $(OBJFILES) = $(TARGET)

rmproper : clean 
	rm -rf $(TARGET)
