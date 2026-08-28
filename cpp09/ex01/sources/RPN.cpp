#include "../headers/RPN.hpp"
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN& other): stack(other.stack)
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		stack = other.stack;
	}
	return *this;
}

RPN::~RPN()
{
}

static bool is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::process_input(std::string input)
{
	char prev = ' ';
	long a;
	long b;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != ' ' && !is_operator(input[i]))
			throw std::runtime_error("Error");
		if (isdigit(prev) && isdigit(input[i]))
			throw std::runtime_error("Error");
		prev = input[i];
		if (isdigit(input[i]))
			stack.push(input[i] - '0');
		if (input[i] == ' ')
			continue ;

		if (is_operator(input[i]))
		{
			if (stack.empty())
				throw std::runtime_error("Error");
			a = stack.top();
			stack.pop();

			if (stack.empty())
				throw std::runtime_error("Error");
			b = stack.top();
			stack.pop();
		}

		if (input[i] == '+')
		{
			if (b + a > INT_MAX )
				throw std::runtime_error("Error");
			stack.push(b + a);
		}
		else if (input[i] == '-')
		{
			if (b - a < INT_MIN)
				throw std::runtime_error("Error");
			stack.push(b - a);
		}
		else if (input[i] == '*')
		{
			if (b * a < INT_MIN || b * a > INT_MAX )
				throw std::runtime_error("Error");
			stack.push(b * a);
		}
		else if (input[i] == '/')
		{
			if (a == 0)
				throw std::runtime_error("Error");
			stack.push(b / a);
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	std::cout << stack.top() << "\n";
}
