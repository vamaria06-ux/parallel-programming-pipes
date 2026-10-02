#include <unistd.h>
#include <cassert>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <string

size_t recv(int& err, int rd, char* b, size_t k)
{
  size_t r = 0;
  while (r < k) {
  err = read(rd, b + r, k - r);
  if (err < 0)
  { 
    break;
  }
  r += err;
  }
  return r;
}
