CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: hello-static hello-dynamic

static: hello-static 

dynamic: hello-dynamic 

hello-static: hello.c
	$(CC) -o hello-static hello.c $(FRAMEWORK) $(STATIC_LIBRARIES)

hello-dynamic: hello.c
	$(CC) -D DYNAMIC=1 -o hello-dynamic hello.c $(FRAMEWORK) $(DYLD_LIBRARIES)
