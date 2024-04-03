#include <iostream>
#include <cstdint>
#include "Serializer.hpp"

int main(){
	Data* data;
	uintptr_t rawData;
	Data* reinterpretData;

	data = new Data;

	std::cout << "Data : " << data << std::endl;
	rawData = Serializer::serialize(data);
	std::cout << "Raw data : " << rawData << std::endl;
	reinterpretData = Serializer::deserialize(rawData);
	std::cout << "Deserialized data: " << reinterpretData << std::endl;

	delete data;

	return 0;
}