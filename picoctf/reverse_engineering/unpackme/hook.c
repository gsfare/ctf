#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset) {
  void* (*orig_mmap)(void *, size_t, int, int, int, off_t) = dlsym(RTLD_NEXT, "mmap");
  printf("Calling hooked mmap\n");
  return orig_mmap(addr, length,prot,flags,fd,offset);
}
