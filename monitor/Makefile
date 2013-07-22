CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: monitor-static 

monitor-static: monitor.c
	$(CC) -o monitor-static monitor.c $(FRAMEWORK) $(STATIC_LIBRARIES)
