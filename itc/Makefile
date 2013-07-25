CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: itc-static 

itc-static: itc.c
	$(CC) -o itc-static itc.c $(FRAMEWORK) $(STATIC_LIBRARIES)
