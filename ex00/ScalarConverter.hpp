#pragma once

#include <iostream>
#include <sstream>

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);

        ScalarConverter& operator=(const ScalarConverter& rhs);

    public:
        ~ScalarConverter(void);

        static void convert(std::string str);

        class ScalarConverterException : public std::exception {
            virtual const char* what() const throw() { return "Unknown type"; }
        };
};