#ifndef UNIT_HPP
#define UNIT_HPP

#include <cstdint>
#include <iostream>
#include "pipe.hpp"

template<class T = int>
class unit : T
{
public:
    void handler(uint64_t n)
    {
        n -= 10;
        static_cast<T*>(this)->handler(n);
    }
};

template<>
class unit<int> {};

template<class T = int>
class end_unit : T
{
public:
    void handler(uint64_t n)
    {
        std::cout<< n << '\n';
    }
};

template<>
class end_unit<int> {};

template<class T = int>
class start_unit : T
{
public:
    void operator()()
    {
        while(true)
        {
            volatile uint64_t n = 5;
            uint64_t copy_n = n;
            copy_n += 25;
            static_cast<T*>(this)->handler(copy_n);
        }
    }
};

template<>
class start_unit<int> {};

using start_unit_t = start_unit<>;
using unit_t = unit<>;
using end_unit_t = end_unit<>;

#endif //UNIT_HPP
