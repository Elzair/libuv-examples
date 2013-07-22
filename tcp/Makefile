CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: server-static 

server-static: server.c
	$(CC) -o server-static server.c $(FRAMEWORK) $(STATIC_LIBRARIES)
