CC = g++ 
CFLAGS = -W -Wall 
SRCFILES = $(wildcard *.cpp) 
HFILES = $(wildcard *.h) 
OBJFILES = Program.o 
TARGET = program

$(OBJFILES) : $(SRCFILES) $(HFILES)
	$(CC) -c $(SRCFILES)

clean : 
	rm -rf $(OBJFILES) = $(TARGET)

rmproper : clean 
	rm -rf $(TARGET)
