#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer & src)
{
    *this = src;
}

Serializer & Serializer::operator=(const Serializer & src)
{
    (void)src;
    return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serealize(Data *ptr)
{
   return (reinterpret_cast<uintptr_t>(ptr));
}
Data *Serializer::deserealize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}