CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: signal-static 

signal-static: signal.c
	$(CC) -o signal-static signal.c $(FRAMEWORK) $(STATIC_LIBRARIES)
