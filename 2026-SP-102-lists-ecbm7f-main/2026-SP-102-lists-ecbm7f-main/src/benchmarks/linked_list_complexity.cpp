#include "linked_list.hpp"
#include <benchmark/benchmark.h>

/*
LinkedList Complexity Analysis
    This program will attempt to "guess" the time complexity of your list
operations. The results may vary depending on the strength and load on your
hardware. You should use this to validate that your LinkedList is efficiently
implemented. To build, use the target: `analysis_linked_list` in the
`src/Makefile`
*/

// --- 1. Random Access ---
static void BM_LinkedList_RandomAccess(benchmark::State &state) {
  LinkedList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.end(), i);

  int index = state.range(0) / 2;
  int sink = 0;
  for (auto _ : state) {
    // Traversal to middle takes N/2 steps
    auto it = list.begin();
    for (int j = 0; j < index; ++j) {
      ++it;
    }
    sink += *it;
    benchmark::DoNotOptimize(sink);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedList_RandomAccess)
    ->Range(1 << 8, 1 << 13)
    ->Complexity(benchmark::oN);

// --- 2. Insert at Head ---
static void BM_LinkedList_InsertHead(benchmark::State &state) {
  LinkedList<int> list;
  // Pre-fill so N is meaningful, though head insertion shouldn't care
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.end(), i);

  for (auto _ : state) {
    // Re-linking pointers is O(1)
    list.insert(list.begin(), 42);
    benchmark::ClobberMemory();

    // Optional: erase to keep N stable, though O(1) won't mind
    state.PauseTiming();
    list.erase(list.begin());
    state.ResumeTiming();
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedList_InsertHead)
    ->Range(1 << 10, 1 << 16)
    ->Complexity(benchmark::o1);

// --- 3. Erase at Tail ---
static void BM_LinkedList_EraseTail(benchmark::State &state) {
  LinkedList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.end(), i);

  for (auto _ : state) {
    state.PauseTiming();
    list.insert(list.end(), 42);
    state.ResumeTiming();

    list.erase(--list.end()); // Keep size stable
    benchmark::ClobberMemory();
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedList_EraseTail)
    ->Range(1 << 10, 1 << 16)
    ->Complexity(benchmark::o1);

// --- 4. Full Traversal ---
static void BM_LinkedList_FullTraversal(benchmark::State &state) {
  LinkedList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.end(), i);

  int sink = 0;
  for (auto _ : state) {
    // Standard sort/search rely on this loop
    for (auto it = list.begin(); it != list.end(); ++it) {
      sink += *it;
    }
    benchmark::DoNotOptimize(sink);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedList_FullTraversal)
    ->Range(1 << 8, 1 << 13)
    ->Complexity(benchmark::oN);

BENCHMARK_MAIN();
