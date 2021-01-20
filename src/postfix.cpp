// Copyright 20.12.20 KostinAndrej
#include "MyStack.h"
#include "postfix.h"
#include <map>

std::string infix2postfix(std::string infix_string) {
    std::map<char, int> prior_symbles = {
            {'(', 0},
            {')', 1},
            {'+', 2},
            {'-', 2},
            {'*', 3},
            {'/', 3},
            {'.', 4},
            {'0', 5},
            {'1', 5},
            {'2', 5},
            {'3', 5},
            {'4', 5},
            {'5', 5},
            {'6', 5},
            {'7', 5},
            {'8', 5},
            {'9', 5},
    };
    std::string postfix_string;
    MyStack<char> stack(200);
    for ( const auto sign : infix_string ) {
        if (sign == ' ')
            continue;
        if (prior_symbles[sign] == 4) {
            postfix_string[postfix_string.size()-1]= sign;
            continue;
        }
        if (prior_symbles[sign] == 5) {
            postfix_string = postfix_string + sign +  ' ';
        }else {
            if (prior_symbles[sign] == 0 ||
                prior_symbles[stack.get()] < prior_symbles[sign] ||
                stack.isEmpty()) {
                stack.push(sign);
            }else {
                while (prior_symbles[sign] <= prior_symbles[stack.get()] &&
                    !stack.isEmpty()) {
                    postfix_string = postfix_string + stack.pop() +  ' ';
                }
                if (prior_symbles[stack.get()] == 0)
                    stack.pop();
                if (prior_symbles[sign] != 1)
                    stack.push(sign);
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix_string = postfix_string + stack.pop() +  ' ';
    }
    postfix_string = postfix_string.substr(0, postfix_string.size()-1);
    return postfix_string;
}
