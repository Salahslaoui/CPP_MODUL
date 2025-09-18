#include "Serializer.hpp"
#include <typeinfo>

int main()
{
	Data a = {4, 767, 12.4};
	Data *b = &a;
	Data *c = NULL;
    size_t s = 0;

	std::cout << "Short: " << b->x << std::endl;
	std::cout << "INT: " << b->y << std::endl;
	std::cout << "DOUBLE: " << b->z << std::endl;
	std::cout << &a << std::endl;
    s = Serializer::serialize(b);
    std::cout << s << std::endl;
    c = Serializer::deserialize(s);
    std::cout << b << std::endl;
}
