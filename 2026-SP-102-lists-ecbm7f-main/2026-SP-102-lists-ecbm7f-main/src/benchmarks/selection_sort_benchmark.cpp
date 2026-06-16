#include "array_list.hpp"
#include "benchmark_functions.hpp"
#include "linked_list.hpp"
#include <benchmark/benchmark.h>

/*
Selection Sort Benchmark
    Compares the performance of your lists for the selection sort algorithm.
    For consistency in your analysis, do not modify this file.
    To build, use the target: `run_bench_selection_sort` in the `src/Makefile`
*/

static void BM_ArrayList_SelectionSort(benchmark::State &state) {
  ArrayList<int> list;
  for (int i = 0; i < state.range(0); ++i) {
    list.insert(list.begin(), i);
  }

  for (auto _ : state) {
    auto start = list.begin();
    auto end = list.end();
    selection_sort<ArrayList<int>::Iterator, int>(start, end);
    benchmark::DoNotOptimize(list);
  }
  state.SetComplexityN(state.range(0));
}

// Register the benchmark and test varying sizes (100 to 100,000)
BENCHMARK(BM_ArrayList_SelectionSort)->Range(100, 100000)->Complexity();

static void BM_LinkedList_SelectionSort(benchmark::State &state) {
  LinkedList<int> list;
  for (int i = 0; i < state.range(0); ++i) {
    list.insert(list.begin(), i);
  }

  for (auto _ : state) {
    auto start = list.begin();
    auto end = list.end();
    selection_sort<LinkedList<int>::Iterator, int>(start, end);
    benchmark::DoNotOptimize(list);
  }
  state.SetComplexityN(state.range(0));
}

// Register the benchmark and test varying sizes (100 to 100,000)
BENCHMARK(BM_LinkedList_SelectionSort)->Range(100, 100000)->Complexity();

BENCHMARK_MAIN();
