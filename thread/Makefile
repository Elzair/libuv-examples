CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: thread-static 

thread-static: thread.c
	$(CC) -o thread-static thread.c $(FRAMEWORK) $(STATIC_LIBRARIES)
