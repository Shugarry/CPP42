#ifndef BITCOIN_HPP
# define BITCOIN_HPP

class Bitcoin
{
	public:
		Bitcoin();
		Bitcoin(const Bitcoin& other);
		Bitcoin& operator=(const Bitcoin& other);
		~Bitcoin();

		int get_day() const;
		int get_month() const;
		int get_year() const;
		float get_value() const;

	private:
		int day;
		int month;
		int year;
		float value;
};

#endif
