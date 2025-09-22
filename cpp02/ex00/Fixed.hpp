#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed {
	private:
		int value;
		static const int fract = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
