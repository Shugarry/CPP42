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

		Span(unsigned int n);

		void add_number(unsigned int x);
		void add_numbers(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		int shortest_span();
		int longest_span();

		class ContainerFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "vector is full";
				}
		};
		class NotEnoughElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "not enough elements in vector";
				}
		};

	private:
		unsigned int n;
		std::vector<unsigned int> vector;
};

#endif
