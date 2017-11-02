#ifndef PIPE_HPP
#define PIPE_HPP

#include "unit.hpp"

template<class... E> class pipe
{
public:
    void handler(uint64_t&) {}
};

template<class S, class... E>
class pipe<S, E...> : pipe<E...>
{
public:
    void handler(uint64_t& n)
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
    void handler(uint64_t& n)
    {
        end.handler(n);
    }
private:
    end_unit end;
};

template<class... UU> class parallel 
{
public:
    void handler(uint64_t&) {}
};

template<class P, class... PP>
class parallel<P, PP...> : parallel<PP...>
{
public:
    void handler(uint64_t& n)
    {
        uint64_t copy_n = n;
        parallel<PP...>::handler(n);
        unit.handler(copy_n);
    }
private:
    P unit;
};

#endif //PIPE_HPP
