CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: fs-static

fs-static: fs.c
	$(CC) -o fs-static fs.c $(FRAMEWORK) $(STATIC_LIBRARIES)
