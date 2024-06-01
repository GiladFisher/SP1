CC = gcc
CFLAGS = -fPIC -Wall -Wextra
LDFLAGS = -shared
LIBS = -lm
RPATH = -Wl,-rpath,.

TARGET_LIB = libpoisson.so
TARGET_EXEC = main

SRC_LIB = libpoisson.c
SRC_EXEC = usepoisslib.c
HEADER = libpoisson.h

.PHONY: all clean

all: $(TARGET_LIB) $(TARGET_EXEC)

$(TARGET_LIB): $(SRC_LIB) $(HEADER)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET_LIB) $(SRC_LIB) $(LIBS)

$(TARGET_EXEC): $(SRC_EXEC) $(HEADER) $(TARGET_LIB)
	$(CC) -o $(TARGET_EXEC) $(SRC_EXEC) -L. -lpoisson $(RPATH)

clean:
	rm -f $(TARGET_LIB) $(TARGET_EXEC)
