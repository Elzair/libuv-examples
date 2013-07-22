CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: watcher-static watcher-dynamic

static: watcher-static

dynamic: watcher-dynamic

watcher-static: watcher.c
	$(CC) -o watcher-static watcher.c $(FRAMEWORK) $(STATIC_LIBRARIES)

watcher-dynamic: watcher.c
	$(CC) -D DYNAMIC=1 -o watcher-dynamic watcher.c $(FRAMEWORK) $(DYLD_LIBRARIES)

