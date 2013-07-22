CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: hello watcher

hello: hello-static hello-dynamic

watcher: watcher-static watcher-dynamic

static: hello-static watcher-static

dynamic: hello-dynamic watcher-dynamic

hello-static: hello.c
	$(CC) -o hello-static hello.c $(FRAMEWORK) $(STATIC_LIBRARIES)

hello-dynamic: hello.c
	$(CC) -D DYNAMIC=1 -o hello-dynamic hello.c $(FRAMEWORK) #$(DYLD_LIBRARIES)

watcher-static: watcher.c
	$(CC) -o watcher-staic watcher.c $(FRAMEWORK) $(STATIC_LIBRARIES)

watcher-dynamic: watcher.c
	$(CC) -D DYNAMIC=1 -o watcher-dynamic watcher.c $(FRAMEWORK)

