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

    std::function<void()> get_handler()
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

    std::function<void()> get_handler()
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

/*template<class S, class M, class... E>
class pipe : pipe <class M, class... E>
{
public:
    pipe()
    :start{pipe<class M, class... E>::get_handler()}
    {}

    std::function<void()> get_handler()
    {
        return start.get_handler();
    }
private:
    S start;
};

template<class S, class... E>
class pipe<start_unit, E>
{
public:
    pipe()
    :end{}, start{end.get_handler()}
    {}

    void operator()()
    {
        start();
    }
private:
    start_unit start;
    pipe<E...> end;
};*/

/*template<class S, class E>
class pipe
{
public:
    pipe()
    :end{}, start{end.get_handler()}
    {}

    void operator()()
    {
        start();
    }
private:
    S start;
    E end;
};*/

/*template<class S, class E>
make_pipe()
{
    
}*/

#endif //COMPOSITOR_HPP
