

size_t send(int& err, int wr, const char* b, size_t k) {
  size_t r = 0;
  while (r < k) {
    err = write(wr, b + r, k - r);
    if (err < 0) {
      if (errno == EINTR) continue;
      break;
    }
    r += err;
  }
  return r;
}
