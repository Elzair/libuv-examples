#include <stdio.h>
#include <uv.h>
#ifdef DYNAMIC
#include <dlfcn.h>
uv_loop_t* (*uln)(void);
int (*ur)(uv_loop_t*, uv_run_mode);
uv_loop_t* (*udl)(void);
int (*uii)(uv_loop_t*, uv_idle_t*);
int (*uist)(uv_idle_t*, uv_idle_cb);
int (*uisp)(uv_idle_t*);
#endif

int64_t counter = 0;

void wait_for_a_while(uv_idle_t *handle, int status) {
  counter++;
  if (counter >= 10e6)
#ifdef DYNAMIC
    uisp(handle);
#else
    uv_idle_stop(handle);
#endif
}

int main(int argc, char **argv) {
  uv_idle_t idler;
#ifdef DYNAMIC
  void *lib_handle = dlopen("libuv.dylib", RTLD_LOCAL|RTLD_LAZY);
  *(void **)(&uln) = dlsym(lib_handle, "uv_loop_new");
  *(void **)(&ur) = dlsym(lib_handle, "uv_run");
  *(void **)(&udl) = dlsym(lib_handle, "uv_default_loop");
  *(void **)(&uii) = dlsym(lib_handle, "uv_idle_init");
  *(void **)(&uist) = dlsym(lib_handle, "uv_idle_start");
  *(void **)(&uisp) = dlsym(lib_handle, "uv_idle_stop");

  uii(udl(), &idler);
  uist(&idler, wait_for_a_while);

  printf("Idling...\n");
  ur(udl(), UV_RUN_DEFAULT);
  
  dlclose(lib_handle);
#else
  uv_idle_init(uv_default_loop(), &idler);
  uv_idle_start(&idler, wait_for_a_while);
  printf("Idling...\n");
  uv_run(uv_default_loop(), UV_RUN_DEFAULT);
#endif
  return 0;
}
