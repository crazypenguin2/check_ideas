#ifndef UNIT_HPP
#define UNIT_HPP

#include <cstdint>
#include <functional>
#include <iostream>

template<class... E> class pipe;

class unit
{
public:
    void handler(uint64_t& n)
    {
        n -= 10;
    }
};

class end_unit
{
public:
    void handler(uint64_t& n)
    {
        std::cout<< n << '\n';
    }
};

template<class... E>
class start_unit : pipe<E...>
{
public:
    void operator()()
    {
        while(true)
        {
            volatile uint64_t n = 5;
            uint64_t copy_n = n;
            copy_n += 25;
            pipe<E...>::handler(copy_n);
        }
    }
};

#endif //UNIT_HPP
