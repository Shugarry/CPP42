#include <iostream>
#include "../headers/Serializer.hpp"

int main() {
	Data data;
	data.data = 42;

	Data* original_ptr = &data;

	uintptr_t raw = Serializer::serialize(original_ptr);
	Data* restored_ptr = Serializer::deserialize(raw);

	std::cout << "original_ptr: " << original_ptr << "\n";
	std::cout << "restored_ptr: " << restored_ptr << "\n";
	std::cout << "\n";
	std::cout << "original data: " << original_ptr->data << "\n";
	std::cout << "restored data: " << restored_ptr->data << "\n";

	return 0;
}
