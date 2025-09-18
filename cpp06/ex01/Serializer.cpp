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

size_t  Serializer::serialize(Data* ptr)
{
	size_t i = reinterpret_cast<size_t>(ptr);
	return i;
}

Data* Serializer::deserialize(size_t raw)
{
	Data *p = reinterpret_cast<Data *>(raw);
	return p;
}

Serializer::~Serializer()
{}
