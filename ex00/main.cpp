#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert <value>" << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        ScalarConverter::convert(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}