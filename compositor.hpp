#ifndef COMPOSITOR_HPP
#define COMPOSITOR_HPP

#include "unit.hpp"

template<class... E> class pipe {};

template<class S, class... E>
class pipe<S, E...> : pipe<E...>
{
public:
    pipe()
    :start{pipe<E...>::get_handler()}
    {}

    auto get_handler()
    {
        return start.get_handler();
    }
private:
    S start;
};

template<>
class pipe<end_unit>
{
public:
    pipe()
    {}

    auto get_handler()
    {
        return end.get_handler();
    }
private:
    end_unit end;
};

template<class... E>
class pipe<start_unit, E...>: pipe<E...>
{
public:
    pipe()
    :start{pipe<E...>::get_handler()}
    {}

    void operator()()
    {
        start();
    }
private:
    start_unit start;
};

#endif //COMPOSITOR_HPP
