#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
	public:
		Array(void): length(0), array(NULL) {};
		Array(const Array &other): length(other.length)
		{
			array = new T[length];
			for (unsigned int i = 0; i < length; i++)
				array[i] = other.array[i];
		};
		Array& operator=(const Array &other)
		{
			if (this != &other)
			{
				delete[] array;
				length = other.length;
				array = new T[length];
				for (unsigned int i = 0; i < length; i++)
					array[i] = other.array[i];
			}
			return *this;
		};
		~Array(void)
		{
			delete[] array;
		};

		Array(unsigned int n): length(n), array(new T[n]) {};
		T &operator[](unsigned int i)
		{
			if (i >= length)
				throw std::out_of_range("index for array out of range");
			return (array[i]);
		};
		const T &operator[](unsigned int i) const
		{
			if (i >= length)
				throw std::out_of_range("index for array out of range");
			return (array[i]);
		};
		unsigned int size(void) const
		{
			return length;
		};

	private:
		unsigned int length;
		T *array;
};

#endif
