// Copyright 20.12.20 KostinAndrej
#include <iostream>
#include <string>
#include "postfix.h"


int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2postfix(s1);
    std::cout << s2 << std::endl;
    std::cout << "2 6 3 * 4 2 - / +";
    return 0;
}
