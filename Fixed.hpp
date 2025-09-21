#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed {
	private:
		int value;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits();
		void setRawBits(int const raw);
}

#endif
