#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat a("ayse");
    try
    {
        Form form1("form1", 15, 100);
        std::cout << form1 << std::endl;
        a.signForm(form1);
        std::cout << form1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "-----" << std::endl;

    try
    {
        Bureaucrat b("bbb", 12);
        std::cout << b << std::endl;
        Form Form2("form2", 12, 124);
        std::cout << Form2 << std::endl;
        b.signForm(Form2);
        std::cout << Form2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
