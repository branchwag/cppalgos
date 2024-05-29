#include <vector>
#include <cstdlib>

std::vector<std::vector<int>> pyramid(std::size_t n) {
  std::vector<std::vector<int>> result;

  for (std::size_t i = 0; i < n; ++i) {
    std::vector<int> subarray(i + 1, 1);
    result.push_back(subarray);
  }
  return result;
}