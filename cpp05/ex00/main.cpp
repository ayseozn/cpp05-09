#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("ayse");
    std::cout << a << std::endl;
    try
    {
        a.increaseDegree();
        std::cout << a << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "------" << std::endl;
    try
    {
        Bureaucrat b("ozen", 150);
        std::cout << b << std::endl;
        b.increaseDegree();
        std::cout << b << std::endl;
        b.reduce_degree();
        std::cout << b << std::endl;

        std::cout << "-----" << std::endl;
        
        Bureaucrat c("cc", 12);
        Bureaucrat d(b);
        std::cout << d << std::endl;
        std::cout << c << std::endl;
        c = b;
        std::cout << c << std::endl;
        c.reduce_degree();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
