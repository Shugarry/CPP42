#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN.";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address pointed to by string: " << &str << std::endl;
	std::cout << "Address pointed to by pointer: " << stringPTR << std::endl;
	std::cout << "Address pointed to by reference: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value inside string: " << str << std::endl;
	std::cout << "Value inside pointer: " << *stringPTR << std::endl;
	std::cout << "Value inside reference: " << stringREF << std::endl;
}
