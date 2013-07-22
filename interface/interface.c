#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

int main() {
  char buf[512];
  uv_interface_address_t *info;
  int count, i;

  uv_interface_addresses(&info, &count);
  i = count;

  printf("Number of intefaces: %d\n", count);
  while (i--) {
    uv_interface_address_t interface = info[i];

    printf("Name: %s\tInternal? %s\n", interface.name,
        interface.is_internal ? "Yes" : "No");

    if (interface.address.address4.sin_family == AF_INET) {
      uv_ip4_name(&interface.address.address4, buf, sizeof(buf));
      printf("IPv4 address: %s\n", buf);
    }
    else if (interface.address.address4.sin_family == AF_INET6) {
      uv_ip6_name(&interface.address.address6, buf, sizeof(buf));
      printf("IPv6 address: %s\n", buf);
    }
  }
  uv_free_interface_addresses(info, count);
  return 0;
}

