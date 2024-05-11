#pragma once

#include <iostream>

typedef struct
{
    char c;
    int i;
    float f;
    double d;
} Data;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &);

        Serializer &operator=(const Serializer &);

    public:
        ~Serializer();
        
        static uintptr_t serealize(Data *ptr);
        static Data *deserealize(uintptr_t raw);
};