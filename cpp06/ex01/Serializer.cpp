#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer &Serializer::operator=(const Serializer &op)
{
	(void)op;
	return (*this);
}

uintptr_t  serialize(void* ptr)
{
	uintptr_t i = reinterpret_cast<uintptr_t>(ptr);
	
}
