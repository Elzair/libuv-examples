CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: udp-static 

udp-static: udp.c
	$(CC) -o udp-static udp.c $(FRAMEWORK) $(STATIC_LIBRARIES)
