CC = gcc
CFLAGS = -Wall -Wextra -g
LIBS = `pkg-config --cflags --libs gtk+-3.0`

TARGET = programa
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(OBJS): main.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -f $(OBJS) $(TARGET)
