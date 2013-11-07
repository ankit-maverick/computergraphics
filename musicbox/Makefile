#

CC = g++

LINKFLAGS = -lGL -lGLU -lglut

OBJECTS = main.o\
			 drawBox.o\
			 resizeHandler.o\
			 keyHandler.o\
			 humanBody.o\
			 drawBody.o\
			 Room.o\
			 mouseHandler.o\
			 bezier.o\
			 loadTexture.o\
			 fileHandler.o	
		
All: $(OBJECTS)
	$(CC) -o MusicBox $(OBJECTS) $(LINKFLAGS)

%.o: %.cc
	$(CC) $< -o

clean:
	rm *.o

