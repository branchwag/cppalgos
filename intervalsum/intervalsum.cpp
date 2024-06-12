#include <vector>
#include <utility>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int,int>> intervals) {
    if (intervals.empty()) return 0;

    std::sort(intervals.begin(), intervals.end());

    std::vector<std::pair<int, int>> merged_intervals;
    merged_intervals.push_back(intervals[0]);

    for (const auto& interval : intervals) {
        auto& last = merged_intervals.back();

        if(interval.first <= last.second) {
            last.second = std::max(last.second, interval.second);
        } else {
            merged_intervals.push_back(interval);
        }
    }

    int total_length = 0;
    for (const auto& interval : merged_intervals) {
        total_length += interval.second - interval.first;
    }
    return total_length;
}