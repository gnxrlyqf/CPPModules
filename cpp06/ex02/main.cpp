#include "Identify.hpp"
#include <cstdlib>
int main()
{
	srand(time(NULL));
    Base *ptr = generate();
    
    std::cout << "Identification by pointer: ";
    identify(ptr);
    
    std::cout << "Identification by reference: ";
    identify(*ptr);
    
    delete (ptr);
    return (0);
}
