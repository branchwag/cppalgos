#include <string>
#include <cctype>
#include <stdexcept>
#include <iostream>
#include <cmath>

double parseExpression(const std::string& expression, size_t& pos);

double parseNumber(const std::string& expression, size_t& pos) {
    double result = 0.0;
    double fraction = 1.0;
    bool isFraction = false;

    while (pos < expression.size() && (isdigit(expression[pos]) || expression[pos] == '.')) {
        if (expression[pos] == '.') {
            isFraction = true;
        } else {
            if (isFraction) {
                fraction /= 10.0;
                result += (expression[pos] - '0') * fraction;
            } else {
                result = result * 10.0 + (expression[pos] - '0');
            }
        }
        pos++;
    }

    return result;
}

double parseFactor(const std::string& expression, size_t& pos) {
    while (pos < expression.size() && isspace(expression[pos])) pos++;

    double sign = 1.0;
    if (pos < expression.size() && expression[pos] == '-') {
        sign = -1.0;
        pos++;
    } else if (pos < expression.size() && expression[pos] == '+') {
        pos++;
    }

    while (pos < expression.size() && isspace(expression[pos])) pos++;

    if (pos < expression.size() && expression[pos] == '(') {
        pos++;
        double result = parseExpression(expression, pos);
        if (pos < expression.size() && expression[pos] == ')') {
            pos++;
        }
        return sign * result;
    } else {
        return sign * parseNumber(expression, pos);
    }
}

double parseTerm(const std::string& expression, size_t& pos) {
    double result = parseFactor(expression, pos);
    while (pos < expression.size()) {
        while (pos < expression.size() && isspace(expression[pos])) pos++;
        if (pos < expression.size() && (expression[pos] == '*' || expression[pos] == '/')) {
            char op = expression[pos++];
            double rhs = parseFactor(expression, pos);
            if (op == '*') {
                result *= rhs;
            } else {
                result /= rhs;
            }
        } else {
            break;
        }
    }
    return result;
}

double parseExpression(const std::string& expression, size_t& pos) {
    double result = parseTerm(expression, pos);
    while (pos < expression.size()) {
        while (pos < expression.size() && isspace(expression[pos])) pos++;
        if (pos < expression.size() && (expression[pos] == '+' || expression[pos] == '-')) {
            char op = expression[pos++];
            double rhs = parseTerm(expression, pos);
            if (op == '+') {
                result += rhs;
            } else {
                result -= rhs;
            }
        } else {
            break;
        }
    }
    return result;
}

double calc(std::string expression) {
    size_t pos = 0;
    return parseExpression(expression, pos);
}

