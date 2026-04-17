#include <iostream>
#include <cstdlib>
#include "Serializer.hpp"

int main() {
	Data *data;
	Data *new_data;
	uintptr_t raw;

	data = (Data *)malloc(sizeof(Data));
	data->i = 42;
	data->s = "Serializer Test";

	{ // Before
		std::cout << "Address: " << &data << std::endl;
		std::cout << data->i << "; " << data->s << std::endl;
	}
	std::cout << "=====================================================" << std::endl;
	{ // Serialize
		raw = Serializer::serialize(data);
		std::cout << "Serialized uintptr_t: 0x" << std::hex << raw << std::endl;
	}
	std::cout << "=====================================================" << std::endl;	
	{ // Deserialize
		new_data = Serializer::deserialize(raw);
	
		std::cout << "Deserialized Data pointer:" << std::endl;
		std::cout << "  Address: " << new_data << std::endl;
		std::cout << "  " << std::dec << new_data->i << "; " << new_data->s << std::endl;
	}
	std::cout << "=====================================================" << std::endl;
	if (new_data == data)
		std::cout << "Success." << std::endl;
	else
		std::cout << "Failure." << std::endl;

	return (0);
}
