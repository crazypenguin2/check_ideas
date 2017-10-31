#ifndef UNIT_HPP
#define UNIT_HPP

#include <cstdint>
#include <functional>
#include <iostream>

template<class... E> class pipe;

class unit
{
public:
    void handler(volatile uint64_t& n)
    {
        n -= 10;
    }
private:
};

class end_unit
{
public:
    void handler(volatile uint64_t& n)
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
            //std::cin >> n;
            n += 25;
            pipe<E...>::handler(n);
        }
    }
private:
};

#endif //UNIT_HPP
