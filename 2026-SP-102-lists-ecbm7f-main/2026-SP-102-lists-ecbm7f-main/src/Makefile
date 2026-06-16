RED    := \033[31m
GREEN  := \033[32m
YELLOW := \033[33m
RESET  := \033[0m

CXX            := g++
CXXFLAGS       := -std=c++17 -O0 -g -Wall -Wextra -Wpedantic -pedantic-errors -Iinclude
BENCH_CXXFLAGS := -std=c++17 -O3 -Wall -Wextra -Wpedantic -pedantic-errors -Iinclude
LDLIBS         := -lbenchmark -lpthread
HEADERS        := $(wildcard include/*)

# Directories
BUILD_DIR := ../build
MAIN_DIR  := example_mains
BENCH_DIR := benchmarks
CODE_DIR := list_implementations

# Executable names
ARRAY_MAIN   := $(BUILD_DIR)/array_main
LINKED_MAIN  := $(BUILD_DIR)/linked_main
GENERIC_MAIN := $(BUILD_DIR)/generic_main
BENCHMARK    := run_bench

all: $(ARRAY_MAIN) $(LINKED_MAIN) $(GENERIC_MAIN)

analysis: analysis_array_list analysis_linked_list

benchmarks: run_bench_random_access run_bench_insertion run_bench_linear_search run_bench_selection_sort

# Individual Test Targets
$(ARRAY_MAIN): $(MAIN_DIR)/array_list.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(LINKED_MAIN): $(MAIN_DIR)/linked_list.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(GENERIC_MAIN): $(MAIN_DIR)/generic_list.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

$(BENCHMARK)_%: $(BENCH_DIR)/%_benchmark.cpp $(HEADERS)
	@printf "$(YELLOW)Compiling benchmark: $(RESET)$*\n"
	$(CXX) $(BENCH_CXXFLAGS) $^ -o $(BUILD_DIR)/$@ $(LDLIBS)
	@printf "$(GREEN)Running benchmark$(RESET)\n"
	@$(BUILD_DIR)/$@

# =========================================================================
# Macro: Generic Benchmark Reporter
# Usage: $(call run_benchmark_report, <ContainerName>, <ExecutableName>)
# =========================================================================
define run_benchmark_report
	@echo "=========================================================================="
	@echo " Running $(1) Complexity Analysis..."
	@echo "=========================================================================="
	@./$(2) --benchmark_format=console 2>/dev/null | awk ' \
		/_BigO/ && !/_RMS/ { \
			split($$1, parts, "_"); \
			name = parts[3]; \
			comp = $$3; \
			gsub(/[()]/, "", comp); \
		} \
		/_RMS/ { \
			rms = $$2 " %"; \
			printf "  %-20s | Target Complexity: O(%-4s) | RMS Error: %s\n", name, comp, rms; \
		}'
	@echo "=========================================================================="
endef

complexity_%: $(BENCH_DIR)/%_complexity.cpp $(CODE_DIR)/%.ipp
	@printf "$(YELLOW)Compiling $* benchmarks...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $< -o $(BUILD_DIR)/$@ $(LDLIBS)

analysis_%: complexity_%
	$(call run_benchmark_report,$*,$(BUILD_DIR)/complexity_$*)

clean:
	rm -f $(ARRAY_MAIN) $(LINKED_MAIN) $(GENERIC_MAIN) $(BUILD_DIR)/$(BENCHMARK)_* $(BUILD_DIR)/complexity_*

.PHONY: all clean analysis_%
