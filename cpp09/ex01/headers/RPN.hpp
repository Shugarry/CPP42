#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <cstdlib>
#include <iostream>
#include <climits>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void process_input(std::string input);

	private:
		std::stack<long> stack;
};

#endif
