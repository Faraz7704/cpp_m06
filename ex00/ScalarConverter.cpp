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

char toChar(const std::string str)
{
    return str.empty() ? '\0' : str[0];
}

int toInt(const std::string str)
{
    std::istringstream iss(str);
    int value;
    iss >> value;
    return value;
}

float toFloat(const std::string str)
{
    std::istringstream iss(str);
    float value;
    iss >> value;
    return value;
}

double toDouble(const std::string str)
{
    std::istringstream iss(str);
    double value;
    iss >> value;
    return value;
}

bool isChar(std::string str)
{
    return str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]);
}

bool isInt(std::string str)
{
    int j = 0;
    
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i(j); i < ( int ) str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool isFloat(std::string str)
{
    if (str.find( '.' ) == std::string::npos || str.back() != 'f' || str.find( '.' ) == 0 || str.find( '.' ) == str.length() - 2)
        return false;
    
    int found = 0;
    int j = 0;
    
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i(j); i < (int)str.length() - 1; i++)
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || found > 1)
            return false;
    }
    return true;
}

bool isDouble(std::string str)
{
    if (str.find('.') == std::string::npos || str.find('.') == 0 || str.find('.') == str.length() - 1)
        return false;
    
    int j = 0;
    int found = 0;
    
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i(j); i < (int)str.length(); i++)
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || found > 1)
            return false;
    }
    return true;
}

bool isLiterals(std::string str)
{
    if (str.compare("nan") == 0 || str.compare( "nanf" ) == 0
        || str.compare("+inf") == 0 || str.compare("+inff") == 0
        || str.compare("-inf") == 0 || str.compare("-inff") == 0
        || str.compare("-inff") == 0 || str.compare("-inff") == 0 
        || str.compare("+inff") == 0 || str.compare("+inff") == 0)
        return true;
    return false;
}

void printChar(std::string str, char c, int i)
{
    if (isLiterals(str) || (!std::isprint(i) && i >= 127))
        std::cout << "Impossible";
    else if (!std::isprint(i))
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

void printInt(std::string str, int i)
{
    if (isLiterals(str) || (!std::isprint(i) && i >= 127))
        std::cout << "Impossible";
    else
        std::cout << i;
    std::cout << std::endl;
}

void printFloat(std::string str, float f)
{
    if (str.compare( "nan" ) == 0 || str.compare( "nanf" ) == 0)
        std::cout << "nanf";
    else if (str.compare( "+inff" ) == 0 || str.compare( "+inf" ) == 0)
        std::cout << "+inff";
    else if (str.compare( "-inff" ) == 0 || str.compare( "-inf" ) == 0)
        std::cout << "-inff";
    else {
        if (f - static_cast<int>(f) == 0)
            std::cout << f << ".0f";
        else
            std::cout << f << "f";
    }
    std::cout << std::endl;
}

void printDouble(std::string str, double d)
{
    if (str.compare( "nan" ) == 0 || str.compare( "nanf" ) == 0)
        std::cout << "nan";
    else if (str.compare( "+inff" ) == 0 || str.compare( "+inf" ) == 0)
        std::cout << "+inf";
    else if (str.compare( "-inff" ) == 0 || str.compare( "-inf" ) == 0)
        std::cout << "-inf";
    else
    {
        if (d - static_cast<int>(d) == 0 )
            std::cout << d << ".0";
        else
            std::cout << d << "f";
    }
    std::cout << std::endl;
}

void print(std::string str, char c, int i, float f, double d)
{
    std::cout << "char: "; printChar(str, c, i);
    std::cout << "int: "; printInt(str, i);
    std::cout << "float: "; printFloat(str, f);
    std::cout << "double: "; printDouble(str, d);
}

void ScalarConverter::convert(std::string str)
{
    char c;
    int i;
    float f;
    double d;

    try {
        if (isChar(str))
        {
            c = toChar(str);
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        }
        else if (isInt(str))
        {
            i = toInt(str);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            c = static_cast<char>(i);
        }
        else if (isFloat(str))
        {
            f = toFloat(str);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            c = static_cast<char>(f);
        }
        else if (isDouble(str))
        {
            d = toDouble(str);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            c = static_cast<char>(d);
        }
        print(str, c, i, f, d);
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}