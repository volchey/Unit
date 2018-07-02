
#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
    virtual ~Base(){};
};
class A : public Base {};
class B : public Base {};
class C : public Base {};

void    identify_from_reference(Base &p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
}


void    identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

Base    *generate()
{
    int i = rand() % 3;
    switch (i)
    {
        case 0 : std::cout << "A" << std::endl;
            return (new A);
        case 1 : std::cout << "B" << std::endl;
            return (new B);
        case 2 : std::cout << "C" << std::endl;
            return (new C);
        default:
            break;
    }
    return NULL;
}

int main()
{
    srand(time(0));
    Base    *base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
}