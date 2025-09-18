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

size_t  Serializer::serialize(void* ptr)
{
	size_t i = reinterpret_cast<size_t>(ptr);
	return i;
}

void* Serializer::deserialize(size_t raw)
{
	void *p = reinterpret_cast<void *>(raw);
	return p;
}
