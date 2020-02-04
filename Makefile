TARGET=valleyterm
INSTDIR=/usr/local/bin
CC=gcc
DEBUG=-g
OPT=-O2
WARN=-Wall
VTE=vte-2.91
CCFLAGS=$(OPT) $(WARN) `pkg-config --cflags $(VTE)`
LD=gcc
LDFLAGS=`pkg-config --libs $(VTE)`
OBJS=term.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)

term.o: term.c
	$(CC) -c $(CCFLAGS) term.c -o term.o

clean:
	rm -f $(OBJS) $(TARGET)

install:
	install -m 755 ./$(TARGET) $(INSTDIR)

