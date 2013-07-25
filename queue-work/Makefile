CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: queue-work-static 

queue-work-static: queue-work.c
	$(CC) -o queue-work-static queue-work.c $(FRAMEWORK) $(STATIC_LIBRARIES)
