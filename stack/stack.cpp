#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<string> plates;

    plates.push("plate1");
    plates.push("plate2");
    plates.push("plates3");

    cout << plates.top();

    return 0;
}
