#include <iostream>
#include "Point.hpp"

void test_case(const std::string& test_name, const Point& a, const Point& b, const Point& c, const Point& p, bool expected) {
	
	bool result = bsp(a, b, c, p);
    std::cout << ">>> Test: " << test_name << std::endl;
    std::cout << "Triangle: (" << a.getX() << "," << a.getY() << "), " 
              << "(" << b.getX() << "," << b.getY() << "), " 
              << "(" << c.getX() << "," << c.getY() << ")" << std::endl;
    std::cout << "\tPoint: (" << p.getX() << "," << p.getY() << ")" << std::endl;
    std::cout << "\tExpected: " << (expected ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "\tResult: " << (result ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "\tStatus: " << (result == expected ? "✅ PASS" : "❌ FAIL") << std::endl;
    std::cout << std::endl;
}

int main() {
	// Test 1: Simple triangle with point clearly inside
	{
		Point a(0, 0);
		Point b(3, 0);
		Point c(1.5f, 3);
		Point p(1.5f, 1);
		test_case("Point clearly inside triangle", a, b, c, p, true);
	}

	// Test 2: Point clearly outside triangle
	{
		Point a(0, 0);
		Point b(3, 0);
		Point c(1.5f, 3);
		Point p(5, 1);
		test_case("Point clearly outside triangle", a, b, c, p, false);
	}    
	// Test 3: Negative coordinates
	{
		Point a(-2, -2);
		Point b(2, -2);
		Point c(0, 2);
		Point p(0, 0);
		test_case("Triangle with negative coords", a, b, c, p, true);
	}

	// Test 4: Very small triangle
	{
		Point a(0, 0);
		Point b(0.1f, 0);
		Point c(0.05f, 0.1f);
		Point p(0.05f, 0.05f);
		test_case("Very small triangle", a, b, c, p, true);
	}
		
	// Test 5: Point at centroid (should be inside)
	{
		Point a(0, 0);
		Point b(3, 0);
		Point c(1.5f, 3);
		Point p(1.5f, 1);
		test_case("Point at centroid", a, b, c, p, true);
	}

	// Test 6: Large coordinates
	{
		Point a(100, 100);
		Point b(200, 100);
		Point c(150, 200);
		Point p(150, 150);
		test_case("Large coordinates", a, b, c, p, true);
	}
	return (0);
}