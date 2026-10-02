#include <unistd.h>
#include <cassert>
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

int main(int argc, char** argv)
{
  assert(argc == 2);
  int err = 0;
  int rd = std::atoi(argv[1]);
  assert(rd > 0);

  size_t n = 0;
  size_t got = recv(err, rd, (char*)&n, sizeof n);
  assert(got == sizeof n);

  std::string msg(n, '\0');
  got = recv(err, rd, &msg[0], n);
  assert(got == n);

  err = close(rd);
  assert(!err);

  fwrite(msg.data(), 1, msg.size(), stdout);
  return 0;
}
