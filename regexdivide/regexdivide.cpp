#include <regex>

// Regular expression to detect whether a binary number is divisible by 7
std::regex solution = std::regex("^(0|(1(01*0)*1(0|01|011|0111|01110|011100|0111001|01110010|011100100|0111001000|01110010000|011100100000|0111001000000)*))$");
