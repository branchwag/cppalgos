#include <iostream>
#include <sstream>
#include <iomanip>  // for std::setfill and std::setw

std::string rgb_to_hex(int r, int g, int b) {
    auto convert = [](int color) -> std::string {
        if (color < 0) color = 0;
        if (color > 255) color = 255;
        std::stringstream ss;
        ss << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << color;
        return ss.str();
    };
    
    return convert(r) + convert(g) + convert(b);
}

int main() {
    // Test cases
    std::cout << rgb_to_hex(255, 255, 255) << std::endl; // "FFFFFF"
    std::cout << rgb_to_hex(255, 255, 300) << std::endl; // "FFFFFF"
    std::cout << rgb_to_hex(0, 0, 0) << std::endl;       // "000000"
    std::cout << rgb_to_hex(148, 0, 211) << std::endl;  // "9400D3"
    return 0;
}
