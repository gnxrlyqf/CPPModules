#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed {
	private:
		int value;
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed(const int n);
		Fixed(const float n);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		Fixed &operator=(const Fixed &other);
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static const Fixed &min(const Fixed &l, const Fixed &r);
		static const Fixed &max(const Fixed &l, const Fixed &r);
		static Fixed &min(Fixed &l, Fixed &r);
		static Fixed &max(Fixed &l, Fixed &r);
};
	
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
