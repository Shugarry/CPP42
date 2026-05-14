#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include <iostream>

int main()
{
    try
	{
		Form form_a("F1", false, 0, 50);
	} 
    catch (std::exception& e)
	{
		std::cout << "F1 error: " << e.what() << "\n";
	}

    try
	{
		Form form_b("F2", false, 50, 151);
	} 
    catch (std::exception& e)
	{
		std::cout << "F2 error: " << e.what() << "\n";
	}

    Bureaucrat a("A", 1);
    Bureaucrat b("B", 150);
    Form form_c("F3", false, 50, 50);

    std::cout << form_c << "\n";
    
    b.sign_form(form_c);
    a.sign_form(form_c);
    
    std::cout << form_c << "\n";

    return 0;
}
