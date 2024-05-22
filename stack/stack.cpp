#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<string> plates;

    plates.push("plate1");
    plates.push("plate2");
    plates.push("plate3");
    std::cout << "Size of stack: " << plates.size() << std::endl;
    std::cout << plates.top();
    plates.pop();
    std::cout << plates.top();

    return 0;
}
