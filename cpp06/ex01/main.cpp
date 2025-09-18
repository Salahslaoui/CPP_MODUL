#include "Serializer.hpp"
#include <typeinfo>

int main()
{
    int *p;
    int *q;
    int a;
    size_t s = 0;
    s = Serializer::serialize(p);
    std::cout << p << std::endl;
    std::cout << s << std::endl;
    q = (int *)Serializer::deserialize(s);
    std::cout << q << std::endl;
}