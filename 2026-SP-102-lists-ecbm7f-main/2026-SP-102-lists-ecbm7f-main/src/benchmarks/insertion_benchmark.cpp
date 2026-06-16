#include "array_list.hpp"
#include "linked_list.hpp"
#include <benchmark/benchmark.h>

/*
Insertion Benchmark
    Compares the performance of your lists for inserting data elements.
    For consistency in your analysis, do not modify this file.
    To build, use the target: `run_bench_insertion` in the `src/Makefile`
*/

struct LargeStruct {
  size_t data[32]; // assume that this type is large enough to prevent optimal
                   // cache use
};

static void BM_ArrayList_HeadInsert(benchmark::State &state) {
  ArrayList<LargeStruct> list;

  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.begin(), LargeStruct());
  for (auto _ : state) {
    state.PauseTiming();
    list.erase(list.end()); // prevent storage array from resizing during bm
    state.ResumeTiming();
    list.insert(list.begin(), LargeStruct());
    benchmark::DoNotOptimize(list);
  }
  state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ArrayList_HeadInsert)->Range(100, 10000)->Complexity();

static void BM_LinkedList_HeadInsert(benchmark::State &state) {
  LinkedList<LargeStruct> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.begin(), LargeStruct());

  for (auto _ : state) {
    list.insert(list.begin(), LargeStruct());
    benchmark::DoNotOptimize(list);
  }
  state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_LinkedList_HeadInsert)->Range(100, 10000)->Complexity();

BENCHMARK_MAIN();
