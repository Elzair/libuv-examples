#include <dlfcn.h>

void load_libuv() {
  void *lib_handle = dlopen("libuv.dylib", RTLD_LOCAL|RTLD_LAZY);
  *(void **)(&uv_loop_new) = dlsym(lib_handle, "uv_loop_new");
  *(void **)(&uv_run) = dlsym(lib_handle, "uv_run");
  *(void **)(&uv_default_loop) = dlsym(lib_handle, "uv_default_loop");
  *(void **)(&uv_idle_init) = dlsym(lib_handle, "uv_idle_init");
  *(void **)(&uv_idle_start) = dlsym(lib_handle, "uv_idle_start");
  *(void **)(&uv_idle_stop) = dlsym(lib_handle, "uv_idle_stop"); 
}

