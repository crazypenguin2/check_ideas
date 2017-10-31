#ifndef PIPE_HPP
#define PIPE_HPP

#include "unit.hpp"

template<class... E> class pipe {};

template<class S, class... E>
class pipe<S, E...> : pipe<E...>
{
public:
    void handler(volatile uint64_t& n)
    {
        start.handler(n);
        pipe<E...>::handler(n);
    }
private:
    S start;
};

template<>
class pipe<end_unit>
{
public:
    void handler(volatile uint64_t& n)
    {
        end.handler(n);
    }
private:
    end_unit end;
};

#endif //PIPE_HPP
