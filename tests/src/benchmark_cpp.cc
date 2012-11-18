#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "test.pb.h"
#include "ssrtb_v6.pb.h"
#include "test.h"

#define Run(type, type_string, data, message_type) \
  message_type var_##type; \
  \
  gettimeofday(&tv1, NULL); \
  for (i=0; i<NLOOP; i++) { \
    var_##type.ParseFromArray(data##_1, sizeof(data##_1)); \
    var_##type.ParseFromArray(data##_2, sizeof(data##_2)); \
  } \
  gettimeofday(&tv2, NULL); \
  delta = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec; \
  printf("cpp %s: %.5f m/s\n", type_string, ((double)NLOOP*2)/delta);

int main() {
  int i = 0;
  double delta;
  struct timeval tv1, tv2;

  Run(uint32, "uint32", BENCMARK_UINT32_DATA, BenchmarkUINT32);
  Run(fixed32, "fixed32", BENCMARK_FIXED32_DATA, BenchmarkFixed32);
  Run(fixed64, "fixed64", BENCMARK_FIXED64_DATA, BenchmarkFixed64);
  Run(string, "string", BENCMARK_STRING_DATA, BenchmarkString);
  Run(bid_request, "openx bid request", OPENX, BidRequest);
  
  return 0;
}