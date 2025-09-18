#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &op);
	public:
		static	size_t serialize(void* ptr);
		static void* deserialize(size_t raw);
};

#endif
