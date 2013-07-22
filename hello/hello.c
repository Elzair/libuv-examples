#include <stdio.h>
#include <uv.h>
#ifdef DYNAMIC
#include <dlfcn.h>
#endif

int main(int argc, char **argv) {
  printf("Hello World!\n");
#ifdef DYNAMIC
  void *lib_handle = dlopen("libuv.dylib", RTLD_LOCAL|RTLD_LAZY);
  uv_loop_t *(*uv_loop_new)(void) = dlsym(lib_handle, "uv_loop_new");
  void (*uv_run)(uv_loop_t *, uv_run_mode) = dlsym(lib_handle, "uv_run");
#endif

  uv_loop_t *loop = uv_loop_new();

  printf("Now quitting.\n");
  uv_run(loop, UV_RUN_DEFAULT);

#ifdef DYNAMIC
  dlclose(lib_handle);
#endif
  return 0;
}
