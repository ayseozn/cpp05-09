#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename templ>
void print(templ& c){std::cout << c << std::endl;}

template <typename templ>
void iter(templ *array, size_t num, void (*func)(templ &))
{
    size_t i = 0;
    while(i < num)
    {
        func(array[i]);
        i++;
    }
}

#endif