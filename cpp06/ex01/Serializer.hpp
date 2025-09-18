#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct s_Data
{
	short x;
	int y;
	double z;
} t_Data;

typedef s_Data Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &op);
		~Serializer();
	public:
		static	size_t serialize(Data* ptr);
		static Data* deserialize(size_t raw);
};

#endif
