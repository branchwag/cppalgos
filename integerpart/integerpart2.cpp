#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>

class IntPart
{
public:
  static std::string part(long long n);

private:
  static void generate_partitions(int n, int max, std::vector<int> &current, std::vector<std::vector<int>> &result);
  static std::vector<std::vector<int>> enum_partitions(int n);
  static std::vector<long long> calculate_products(const std::vector<std::vector<int>> &partitions);
  static std::string format_result(const std::vector<long long> &products);
};

void IntPart::generate_partitions(int n, int max, std::vector<int> &current, std::vector<std::vector<int>> &result) {
  if (n == 0) {
    result.push_back(current);
    return;
  }
  for (int i = std::min(n, max); i >= 1; --i) {
    current.push_back(i);
    generate_partitions(n - i, i, current, result);
    current.pop_back();
  }
}

std::vector<std::vector<int>> IntPart::enum_partitions(int n) {
  std::vector<std::vector<int>> partitions;
  std::vector<int> current;
  generate_partitions(n, n, current, partitions);
  return partitions;
}

std::vector<long long> IntPart::calculate_products(const std::vector<std::vector<int>> &partitions) {
  std::set<long long> products;
  for (const auto &partition : partitions) {
    long long product = 1;
    for (int num : partition) {
      product *= num;
    }
    products.insert(product);
  }
  return std::vector<long long>(products.begin(), products.end());
}

std::string IntPart::format_result(const std::vector<long long> &products) {
  if (products.empty()) return "Range: 0 Average: 0.00 Median: 0.00";
  
  long long range = products.back() - products.front();
  double average = std::accumulate(products.begin(), products.end(), 0LL) / static_cast<double>(products.size());

  double median;
  size_t size = products.size();
  if (size % 2 == 0) {
    median = (products[size / 2 - 1] + products[size / 2]) / 2.0;
  } else {
    median = products[size / 2];
  }

  std::ostringstream result;
  result << "Range: " << range
         << " Average: " << std::fixed << std::setprecision(2) << average
         << " Median: " << median;

  return result.str();
}

std::string IntPart::part(long long n) {
  auto partitions = enum_partitions(n);
  auto products = calculate_products(partitions);
  return format_result(products);
}
