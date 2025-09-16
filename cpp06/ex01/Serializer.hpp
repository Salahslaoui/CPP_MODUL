#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &op);
	public:
		static	uintptr_t  serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
}

#endif
