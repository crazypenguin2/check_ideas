#ifndef UNIT_HPP
#define UNIT_HPP

#include <functional>
#include <iostream>

class unit
{
public:
    unit(std::function<void()> c)
    :callback{c}
    {}

    unit() = delete;

    std::function<void()> get_handler()
    {
        return std::bind(&unit::handler, this);
    }
private:
    std::function<void()> callback;

    void handler()
    {
        std::cout<< "unit:";
        callback();
    }
};

class end_unit
{
public:
    std::function<void()> get_handler()
    {
        return std::bind(&end_unit::handler, this);
    }
private:
    void handler()
    {
        std::cout<< "end\n";
    }
};

class start_unit
{
public:
    start_unit(std::function<void()> c)
    :callback{c}
    {}

    start_unit() = delete;

    void operator()()
    {
        while(true)
        {
            std::string s;
            std::cin >> s;
            std::cout << s<< ":";
            callback();
        }
    }
private:
    std::function<void()> callback;
};

#endif //UNIT_HPP
