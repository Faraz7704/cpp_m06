#include "Serializer.hpp"

int main ()
{
    Data *a = new Data();
    Data *b;
    uintptr_t raw;

    a->c = '0';
    a->i = 0;
    a->f = 3.23f;
    a->d = 23.12;

    std::cout << "data address: " << a << std::endl;
    std::cout << a->c << "\t" << a->i << "\t" << a->f << "\t" << a->d << std::endl;
    
    raw = Serializer::serealize(a);
    std::cout << "raw serialize: " << raw << std::endl;
    std::cout << "raw address: " << &raw << std::endl;

    b = Serializer::deserealize(raw);
    std::cout << "deserialize address: " << b << std::endl;
    std::cout << b->c  << "\t" << b->i << "\t" << b->f << "\t" << b->d << std::endl;

    delete a;
    return (0);
}