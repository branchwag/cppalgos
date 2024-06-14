#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

std::string to_postfix(std::string infix) {
    std::string postfix;
    std::stack<char> stack;

    std::unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 3;
    
    std::unordered_map<char, bool> rightAssociative;
    rightAssociative['+'] = false;
    rightAssociative['-'] = false;
    rightAssociative['*'] = false;
    rightAssociative['/'] = false;
    rightAssociative['^'] = true;


    for (char c : infix) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); 
        } else {
            while (!stack.empty() && stack.top() != '(' && 
                   (precedence[stack.top()] > precedence[c] || 
                   (precedence[stack.top()] == precedence[c] && !rightAssociative[c]))) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    
    return postfix;
}