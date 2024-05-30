#include "iter.hpp"

int main()
{
    int ary[3] = {1, 2, 3};
    ::iter(ary, 3, print);

    std::string ar[3] = {"ay", "se"};
    ::iter(ar, 2, print);
}