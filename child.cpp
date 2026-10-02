#include <unistd.h>
#include <sys/wait.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>

size_t recv(int& err, int rd, char* b, size_t k)
{
  size_t r = 0;
  while (r < k)
  {
    err = read(rd, b + r, k - r);
    if (err < 0)
    { 
      break;
    }
    r += err;
  }
  return r;
}

int main(int argc, char** argv)
{
  assert(argc == 2);
  int err = 0;
  int rd = std::atoi(argv[1]);
  assert(rd > 0);

  size_t n = 0;
  recv(err, rd, (char*)&n, sizeof n);
  assert(err > 0);

  char* msg = new char[n + 1]{};
  recv(err, rd, msg, n);
  assert(err > 0);

  err = close(rd);
  assert(!err);
  err = printf("%s", msg);
  assert(err > 0);
  delete[] msg;
}
