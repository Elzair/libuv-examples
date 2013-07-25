CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: lock-static 

lock-static: lock.c
	$(CC) -o lock-static lock.c $(FRAMEWORK) $(STATIC_LIBRARIES)
