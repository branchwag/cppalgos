#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
    std::vector<std::string> result;

    for (const auto& dir : arr) {
        if (!result.empty()){
            const std::string& last = result.back();
            if ((dir == "NORTH" && last == "SOUTH") || (dir == "SOUTH" && last == "NORTH") || (dir == "EAST" && last == "WEST") || (dir == "WEST" && last == "EAST")) {
                result.pop_back();
            } else {
                result.push_back(dir);
            }
        } else {
            result.push_back(dir);
        }
    }

    return result;
}

int main() {
    std::vector<std::string> directions = {"NORTH", "SOUTH", "EAST", "WEST"};
    std::vector<std::string> reduced = dirReduc(directions);

    for(const auto& dir : reduced) {
        std::cout << dir << " ";
    }

    return 0;
}
