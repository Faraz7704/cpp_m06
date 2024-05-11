#include <iostream>

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void)
{
    if (std::rand() % 3 == 0)
        return (new A);
    else if (std::rand() % 3 == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    }
    catch(const std::exception& e) {}

    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    }
    catch(const std::exception& e) {}

    std::cout << "unknown" << std::endl;
}

int     main(void)
{
    Base *a = generate();
    Base *b = generate();
    Base *c = generate();
    Base *d = generate();

    std::cout << "/* **************************************** */" << std::endl;

    std::cout << "a* = "; identify(a);
    std::cout << "a& = "; identify(*a); std::cout << std::endl;

    std::cout << "b* = "; identify(b);
    std::cout << "b& = "; identify(*b); std::cout << std::endl;

    std::cout << "c* = "; identify(c);
    std::cout << "c& = "; identify(*c); std::cout << std::endl;

    std::cout << "d* = "; identify(d);
    std::cout << "d& = "; identify(*d); std::cout << std::endl;

    std::cout << "/* ***************************************** */" << std::endl;

    delete a;
    delete b;
    delete c;
    delete d;

    return (0);
}