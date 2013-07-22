CC=cc
FRAMEWORK=-framework CoreFoundation -framework CoreServices
STATIC_LIBRARIES=/usr/local/lib/libuv.a
#DYLD_LIBRARIES=/usr/local/lib/libuv.dylib

all: dns-static 

dns-static: dns.c
	$(CC) -o dns-static dns.c $(FRAMEWORK) $(STATIC_LIBRARIES)
