CC = gcc
CFLAGS = -o2 -Wall
LDFLAGS =

TARGET = nil
PROJFILES = nilstruct.c  multicast.c  test.c

all:
	$(CC) $(CFLAGS) $(PROJFILES) -o $(TARGET) $(LDFLAGS)
  
clean:   
	rm -f *.o  
	rm -f $(TARGET)  

