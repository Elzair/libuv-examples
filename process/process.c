#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

uv_loop_t *loop;
uv_process_t child_req;
uv_process_options_t options;

void on_exit(uv_process_t *req, int exit_status, int term_signal) {
  fprintf(stderr, "Process exited with status %d, signal %d\n", exit_status, term_signal);
  uv_close((uv_handle_t*)req, NULL);
}

int main() {
  loop = uv_default_loop();

  char *args[] = { "sleep", "100", NULL };

  options.exit_cb = NULL;
  options.file = "sleep";
  options.args = args;
  options.flags = UV_PROCESS_DETACHED;

  if (uv_spawn(loop, &child_req, options)) {
    fprintf(stderr, "Error!\n");
    return 1;
  }
  fprintf(stderr, "Launched sleep with PID %d\n", child_req.pid);
  uv_unref((uv_handle_t*) &child_req);

  return uv_run(loop, UV_RUN_DEFAULT);
}

