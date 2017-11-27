#ifndef PIPE_HPP
#define PIPE_HPP

template<class... E>
class pipe 
{};

template<template<class> class S, class... E>
class pipe<S<int>, E...> : pipe<E...>
{
public:
  using T = S<typename pipe<E...>::T>;
};

template<>
class pipe<>
{
public:
  class T{};
};

template <class... E>
auto make_pipe(E... e)
{
  using P = typename pipe<E...>::T;
  return P{}; 
};

#endif //PIPE_HPP
