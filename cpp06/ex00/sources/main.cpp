#include "../headers/ScalarConverter.hpp"
#include <iostream>

int main() {
    const char* tests[] = {
        // chars
        "a",
        "z",
        "0",

        // ints
        "42",
        "-42",
        "2147483647",
        "-2147483648",

        // int overflow
        "2147483648",
        "-2147483649",
        "999999999999999999999",

        // doubles
        "4.2",
        "-4.2",
        "0.0",
        "1.7976931348623157e+308",

        // double overflow
        "1e309",

        // floats
        "4.2f",
        "-4.2f",
        "0.0f",
        "3.4028235e+38f",

        // float overflow
        "1e39f",

        // pseudo literals
        "nan",
        "nanf",
        "+inf",
        "-inf",
        "+inff",
        "-inff",

        // non displayable chars
        "7",
        "31",
        "127",

        // invalid
        "",
        " ",
        "abc",
        "42abc",
        "4.2ff",
        "--42",
        "++42",
        ".",
        "f"
    };

    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++) {
        std::cout << "=== \"" << tests[i] << "\" ===" << std::endl;
        ScalarConverter::convert(tests[i]);
        std::cout << std::endl;
    }

    return 0;
}
