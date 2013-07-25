CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: process-static 

process-static: process.c
	$(CC) -o process-static process.c $(FRAMEWORK) $(STATIC_LIBRARIES)
