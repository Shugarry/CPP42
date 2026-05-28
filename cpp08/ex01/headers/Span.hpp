#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	public:
		Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void add_number(unsigned int x);
		int shortest_span();
		int longest_span();

		class ContainerFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		unsigned int n;
		std::vector<int> vector;
};

#endif
