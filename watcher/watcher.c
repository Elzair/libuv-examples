#include <stdio.h>
#include <uv.h>
#ifdef DYNAMIC
#include <dlfcn.h>
uv_loop_t* (*uv_loop_new)(void);
int (*uv_run)(uv_loop_t*, uv_run_mode);
uv_loop_t* (*uv_default_loop)(void);
int (*uv_idle_init)(uv_loop_t*, uv_idle_t*);
int (*uv_idle_start)(uv_idle_t*, uv_idle_cb);
int (*uv_idle_stop)(uv_idle_t*);
#endif

int64_t counter = 0;

void wait_for_a_while(uv_idle_t *handle, int status) {
  counter++;
  if (counter >= 10e6)
    uv_idle_stop(handle);
}

int main(int argc, char **argv) {
#ifdef DYNAMIC
  void *lib_handle = dlopen("libuv.dylib", RTLD_LOCAL|RTLD_LAZY);
  *(void **)(&uv_loop_new) = dlsym(lib_handle, "uv_loop_new");
  *(void **)(&uv_run) = dlsym(lib_handle, "uv_run");
  *(void **)(&uv_default_loop) = dlsym(lib_handle, "uv_default_loop");
  *(void **)(&uv_idle_init) = dlsym(lib_handle, "uv_idle_init");
  *(void **)(&uv_idle_start) = dlsym(lib_handle, "uv_idle_start");
  *(void **)(&uv_idle_stop) = dlsym(lib_handle, "uv_idle_stop");
#endif
  
  uv_idle_t idler;

  uv_idle_init(uv_default_loop(), &idler);
  uv_idle_start(&idler, wait_for_a_while);

  printf("Idling...\n");

  uv_run(uv_default_loop(), UV_RUN_DEFAULT);

#ifdef DYNAMIC
  dlclose(lib_handle);
#endif

  return 0;
}
