//
//  main.c
//  Benchmark
//

#include <stdio.h>
#include "Benchmark.h"

int main(int argc, const char * argv[]) {
  uint64_t time = benchmark(100000, ^{
    // Do stuff here
  });
  
  printf("Time %lld\n", time);
  return 0;
}
