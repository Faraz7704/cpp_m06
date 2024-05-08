#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    *this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    return *this;
}

ScalarConverter::~ScalarConverter(void)
{}

void ScalarConverter::convert(std::string const &value)
{
    char type = '\0';
    if (value.length() == 1 && std::isalpha(value[0]) && std::isprint(value[0]))
        type = 'c';

    // std::cout << "char: " << c->printChar(av[1]);
    // std::cout << "int: " << printInt(av[1]);
    // std::cout << "float: " << printFloat(av[1]);
    // std::cout << "double: " << printFloat(av[1]);
}