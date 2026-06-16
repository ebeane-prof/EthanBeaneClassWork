#include "array_list.hpp"
#include <benchmark/benchmark.h>

/*
ArrayList Complexity Analysis
    This program will attempt to "guess" the time complexity of your list
operations. The results may vary depending on the strength and load on your
hardware. You should use this to validate that your ArrayList is efficiently
implemented. To build, use the target: `analysis_array_list` in the
`src/Makefile`
*/

// --- 1. Random Access ---
static void BM_ArrayList_RandomAccess(benchmark::State &state) {
  ArrayList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.end(), i);

  int index = state.range(0) / 2;
  for (auto _ : state) {
    // Testing the specific iterator math used in sort/search
    auto it = list.begin() + index;
    benchmark::DoNotOptimize(*it);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ArrayList_RandomAccess)
    ->Range(1 << 10, 1 << 16)
    ->Complexity(benchmark::o1);

// --- 2. Insert at Head ---
static void BM_ArrayList_InsertHead(benchmark::State &state) {
  for (auto _ : state) {
    state.PauseTiming();
    ArrayList<int> list;
    for (int i = 0; i < state.range(0); ++i)
      list.insert(list.end(), i);
    state.ResumeTiming();

    // This requires shifting N elements
    list.insert(list.begin(), 42);
    benchmark::ClobberMemory();
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ArrayList_InsertHead)
    ->Range(1 << 8, 1 << 13)
    ->Complexity(benchmark::oN);

// --- 3. Erase from Middle ---
static void BM_ArrayList_EraseMiddle(benchmark::State &state) {
  ArrayList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.end(), i);

  for (auto _ : state) {
    // Re-insert to keep N constant for the regression
    state.PauseTiming();
    list.insert(list.end(), 42);
    state.ResumeTiming();

    // Erasing from middle requires shifting N/2 elements
    auto it = list.begin() + (list.size() / 2);
    list.erase(it);

    benchmark::ClobberMemory();
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_ArrayList_EraseMiddle)
    ->Range(1 << 8, 1 << 13)
    ->Complexity(benchmark::oN);

BENCHMARK_MAIN();
