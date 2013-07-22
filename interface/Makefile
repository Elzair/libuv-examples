CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: interface-static 

interface-static: interface.c
	$(CC) -o interface-static interface.c $(FRAMEWORK) $(STATIC_LIBRARIES)
