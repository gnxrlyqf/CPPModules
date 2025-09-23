#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		Fixed(const int n);
		Fixed(const float n);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};
	
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
