#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int num);
		Fixed(const float num);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		int toInt() const;
		float toFloat() const;
	private:
		int raw_value;
		static const int fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif
