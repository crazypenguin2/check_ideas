#ifndef UNIT_HPP
#define UNIT_HPP

#include <functional>
#include <iostream>

using callback_t = std::function<void()>;

class unit
{
public:
    unit(callback_t c)
    :callback{c}
    {}

    unit() = delete;

    auto get_handler()
    {
        return [this](){ handler(); };
    }
private:
    callback_t callback;

    void handler()
    {
        std::cout<< "unit:";
        callback();
    }
};

class end_unit
{
public:
    auto get_handler()
    {
        return [this](){ handler(); };
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
    start_unit(callback_t c)
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
    callback_t callback;
};

#endif //UNIT_HPP
