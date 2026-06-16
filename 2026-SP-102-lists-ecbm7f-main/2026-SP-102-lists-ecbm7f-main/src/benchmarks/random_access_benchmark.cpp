#include "array_list.hpp"
#include "linked_list.hpp"
#include <benchmark/benchmark.h>
#include <random>
#include <vector>

/*
Random Access Benchmark
    Compares the performance of your lists for accessing a random index.
    For consistency in your analysis, do not modify this file.
    To build, use the target: `run_bench_random_access` in the `src/Makefile`
*/

static void BM_ArrayList_RandomAccess(benchmark::State &state) {
  ArrayList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.begin(), i);

  // Pre-generate a sequence of indices
  std::mt19937 rng(1337);
  std::uniform_int_distribution<int> dist(0, state.range(0) - 1);
  std::vector<int> random_indices;
  for (int i = 0; i < 10000; ++i)
    random_indices.push_back(dist(rng));

  size_t idx = 0;
  int sink = 0;

  // Benchmark only the traversal
  for (auto _ : state) {
    int index = random_indices[idx++ % random_indices.size()];
    auto it = list.begin();
    for (int j = 0; j < index; ++j) {
      ++it;
    }
    sink += *it;
    benchmark::DoNotOptimize(sink);
  }
  state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ArrayList_RandomAccess)->Range(100, 100000)->Complexity();

static void BM_LinkedList_RandomAccess(benchmark::State &state) {
  LinkedList<int> list;
  for (int i = 0; i < state.range(0); ++i)
    list.insert(list.begin(), i);

  // Pre-generate a sequence of indices
  std::mt19937 rng(1337);
  std::uniform_int_distribution<int> dist(0, state.range(0) - 1);
  std::vector<int> random_indices;
  for (int i = 0; i < 10000; ++i)
    random_indices.push_back(dist(rng));

  size_t idx = 0;
  int sink = 0;

  // Benchmark only the traversal
  for (auto _ : state) {
    int index = random_indices[idx++ % random_indices.size()];
    auto it = list.begin();
    for (int j = 0; j < index; ++j) {
      ++it;
    }
    sink += *it;
    benchmark::DoNotOptimize(sink);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinkedList_RandomAccess)->Range(100, 100000)->Complexity();
BENCHMARK_MAIN();
