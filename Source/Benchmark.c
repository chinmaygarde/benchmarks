//
//  Benchmark.c
//  Benchmark
//
//  Created by Chinmay Garde on 12/26/12.
//  Copyright (c) 2012 Chinmay. All rights reserved.
//

#include "Benchmark.h"
#include <mach/mach_time.h>
#include <pthread.h>

static uint64_t current_time() {
  mach_timebase_info_data_t timebase;
  mach_timebase_info(&timebase);
  return mach_absolute_time() * (double)timebase.numer / (double)timebase.denom;
}

static uint64_t __benchmark_loop_cost = 0;
static void _calculate_loop_cost() {
  uint64_t total_iterations = 10000000ul;
  
  void (^dummyBlock)(void) = ^{};
  
  uint64_t time_cost = current_time();
  for(uint64_t i=0; i<total_iterations; i++) {
    dummyBlock();
  }
  time_cost = current_time() - time_cost;
  
  __benchmark_loop_cost = time_cost / total_iterations;
}

static uint64_t loop_cost() {
  static pthread_once_t once_token = PTHREAD_ONCE_INIT;
  pthread_once(&once_token, _calculate_loop_cost);
  
  return __benchmark_loop_cost;
}

uint64_t benchmark(size_t count, void(^workblock)(void)) {
  uint64_t time_cost = current_time();
  for (int i=0; i<count; i++) {
    workblock();
  }
  time_cost = current_time() - time_cost;
  return (time_cost / count) - loop_cost();
}
