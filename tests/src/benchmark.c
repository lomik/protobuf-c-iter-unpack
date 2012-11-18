#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "test.pb-c.h"
#include "test.pb-iter.h"
#include "ssrtb_v6.pb-c.h"
#include "ssrtb_v6.pb-iter.h"
#include "test.h"

typedef struct {
  size_t index;
  char buffer[65535];
} FakeAllocatorData;

static void *perf_system_alloc(void *adata, size_t size) {
  if (size == 0)return NULL; 
  void *res = NULL;
  res = (void*)(((FakeAllocatorData*)adata)->buffer+((FakeAllocatorData*)adata)->index);
  ((FakeAllocatorData*)adata)->index += (size + 31) & ~31;
  return res;
}
 
static void perf_system_free (void *adata, void *data){
  //((FakeAllocatorData*)adata)->index=0;
}

#define benchmark_bid_request__iter_unpack bid_request__iter_unpack
#define benchmark_bid_request__unpack bid_request__unpack
#define benchmark_bid_request__free_unpacked bid_request__free_unpacked

#define RunFastBenchmark(type, type_string, data)   \
  gettimeofday(&tv1, NULL); \
  for (i=0; i<NLOOP; i++) { \
    if (benchmark_##type##__iter_unpack(data##_1, sizeof(data##_1), \
                     iter_msg_buffer, iter_msg_buffer_size) < 0) { \
      printf("protobuf-c-iter %s unpack failed\n", type_string); \
    } \
    if (benchmark_uint32__iter_unpack(data##_2, sizeof(data##_2), \
                     iter_msg_buffer, iter_msg_buffer_size) < 0) { \
      printf("protobuf-c-iter %s unpack failed\n", type_string); \
    } \
  } \
  gettimeofday(&tv2, NULL); \
  delta = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec;\
  printf("protobuf-c-iter %s: %.5f m/s\n", type_string, ((double)NLOOP*2)/delta); 


#define RunProtocFastBenchmark(type, type_string, data) \
  gettimeofday(&tv1, NULL); \
  for (i=0; i<NLOOP; i++) { \
    allocator_data.index = 0; \
    if (benchmark_##type##__unpack(&perf_allocator, sizeof(data##_1), data##_1) == NULL) { \
      printf("protoc-c %s (fast allocator) unpack failed\n", type_string); \
      return 1; \
    } \
    allocator_data.index = 0; \
    if (benchmark_##type##__unpack(&perf_allocator, sizeof(data##_2), data##_2) == NULL) { \
      printf("protoc-c %s (fast allocator) unpack failed\n", type_string); \
      return 1; \
    } \
  } \
  gettimeofday(&tv2, NULL); \
  delta = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec; \
  printf("protoc-c %s (fast allocator): %.5f m/s\n", type_string, ((double)NLOOP*2)/delta);


#define RunProtocMallocBenchmark(type, type_string, data, message_type) \
  message_type* var_##type; \
  gettimeofday(&tv1, NULL); \
  for (i=0; i<NLOOP; i++) { \
    if ((var_##type = benchmark_##type##__unpack(NULL, sizeof(data##_2), data##_2)) == NULL) { \
      printf("protoc-c %s (malloc) unpack failed\n", type_string); \
      return 1; \
    } \
    benchmark_##type##__free_unpacked(var_##type, NULL); \
    if ((var_##type = benchmark_##type##__unpack(NULL, sizeof(data##_2), data##_2)) == NULL) { \
      printf("protoc-c %s (malloc) unpack failed\n", type_string); \
      return 1; \
    } \
    benchmark_##type##__free_unpacked(var_##type, NULL); \
  } \
  gettimeofday(&tv2, NULL); \
  delta = (tv2.tv_sec - tv1.tv_sec) * 1000000 + tv2.tv_usec - tv1.tv_usec; \
  printf("protoc-c %s (malloc): %.5f m/s\n", type_string, ((double)NLOOP*2)/delta);


int main() {
  int i = 0;
  double delta;
  
  uint8_t iter_msg_buffer[65535];
  size_t iter_msg_buffer_size = 65535;
  
  FakeAllocatorData allocator_data;
  allocator_data.index = 0;
  
  ProtobufCAllocator perf_allocator = {
    perf_system_alloc,
    perf_system_free,
    NULL,
    65535,
    &allocator_data
  };
  
  struct timeval tv1, tv2;

  RunFastBenchmark(uint32, "uint32", BENCMARK_UINT32_DATA);
  RunProtocFastBenchmark(uint32, "uint32", BENCMARK_UINT32_DATA);
  RunProtocMallocBenchmark(uint32, "uint32", BENCMARK_UINT32_DATA, BenchmarkUINT32);
  
  RunFastBenchmark(fixed32, "fixed32", BENCMARK_FIXED32_DATA);
  RunProtocFastBenchmark(fixed32, "fixed32", BENCMARK_FIXED32_DATA);
  RunProtocMallocBenchmark(fixed32, "fixed32", BENCMARK_FIXED32_DATA, BenchmarkFixed32);
  
  RunFastBenchmark(fixed64, "fixed64", BENCMARK_FIXED64_DATA);
  RunProtocFastBenchmark(fixed64, "fixed64", BENCMARK_FIXED64_DATA);
  RunProtocMallocBenchmark(fixed64, "fixed64", BENCMARK_FIXED64_DATA, BenchmarkFixed64);
  
  RunFastBenchmark(string, "string", BENCMARK_STRING_DATA);
  RunProtocFastBenchmark(string, "string", BENCMARK_STRING_DATA);
  RunProtocMallocBenchmark(string, "string", BENCMARK_STRING_DATA, BenchmarkString);
  
  RunFastBenchmark(bid_request, "openx bid request", OPENX);
  RunProtocFastBenchmark(bid_request, "openx bid request", OPENX);
  RunProtocMallocBenchmark(bid_request, "openx bid request", OPENX, BidRequest);
  
  return 0;
}
