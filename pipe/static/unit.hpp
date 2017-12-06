#ifndef UNIT_HPP
#define UNIT_HPP

#include <cstdint>
#include <iostream>
#include "pipe.hpp"

template<class T, class N = none>
class unit : N
{
public:
    void handler(T n)
    {
        n -= 10;
        static_cast<N*>(this)->handler(n);
    }
};

template<class T>
class unit<T, none> {};

template<class T, class N = none>
class end_unit : N
{
public:
    void handler(T n)
    {
        std::cout<< n << '\n';
    }
};

template<class T>
class end_unit<T, none> {};

template<class T, class N = none>
class start_unit : N
{
public:
    void operator()()
    {
        while(true)
        {
            volatile T n = 5;
            T copy_n = n;
            copy_n += 25;
            static_cast<N*>(this)->handler(copy_n);
        }
    }
};

template<class T>
class start_unit<T, none> {};

//using start_unit_t = start_unit<>;
//using unit_t = unit<>;
//using end_unit_t = end_unit<>;

#endif //UNIT_HPP
