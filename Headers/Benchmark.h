//
//  Benchmark.h
//  Benchmark
//
//  Created by Chinmay Garde on 12/26/12.
//  Copyright (c) 2012 Chinmay. All rights reserved.
//

#ifndef Benchmark_Benchmark_h
#define Benchmark_Benchmark_h

#include <stdint.h>
#include <stdio.h>

__BEGIN_DECLS

uint64_t benchmark(size_t count, void(^workblock)(void));

__END_DECLS

#endif
