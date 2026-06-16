#include "array_list.hpp"
#include "benchmark_functions.hpp"
#include "linked_list.hpp"
#include <benchmark/benchmark.h>

/*
Linear Search Benchmark
    Compares the performance of your lists for the linear search algorithm.
    For consistency in your analysis, do not modify this file.
    To build, use the target: `run_bench_linear_search` in the `src/Makefile`
*/

static void BM_ArrayList_LinearSearch(benchmark::State &state) {
  ArrayList<int> list;
  for (int i = 0; i < state.range(0); ++i) {
    list.insert(list.begin(), i);
  }

  // We search for a number that doesn't exist to force worst-case
  int target = -1;

  for (auto _ : state) {
    auto start = list.begin();
    auto end = list.end();
    benchmark::DoNotOptimize(linear_search(start, end, target));
  }
  state.SetComplexityN(state.range(0));
}

// Register the benchmark and test varying sizes (100 to 100,000)
BENCHMARK(BM_ArrayList_LinearSearch)->Range(100, 100000)->Complexity();

static void BM_LinkedList_LinearSearch(benchmark::State &state) {
  LinkedList<int> list;
  for (int i = 0; i < state.range(0); ++i) {
    list.insert(list.begin(), i);
  }

  // We search for a number that doesn't exist to force worst-case
  int target = -1;

  for (auto _ : state) {
    auto start = list.begin();
    auto end = list.end();
    benchmark::DoNotOptimize(linear_search(start, end, target));
  }
  state.SetComplexityN(state.range(0));
}

// Register the benchmark and test varying sizes (100 to 100,000)
BENCHMARK(BM_LinkedList_LinearSearch)->Range(100, 100000)->Complexity();

BENCHMARK_MAIN();
