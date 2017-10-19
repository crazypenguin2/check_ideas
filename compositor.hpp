#ifndef COMPOSITOR_HPP
#define COMPOSITOR_HPP

template<class S, class E>
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
};

/*template<class S, class E>
make_pipe()
{
    
}*/

#endif //COMPOSITOR_HPP
