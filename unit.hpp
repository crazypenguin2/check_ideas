#ifndef UNIT_HPP
#define UNIT_HPP

#include <functional>
#include <iostream>

using callback_t = std::function<void(std::string&&)>;

class unit
{
public:
    unit(callback_t c)
    :callback{c}
    {}

    unit() = delete;

    auto get_handler()
    {
        return [this](std::string&& s){ handler(std::move(s)); };
    }
private:
    callback_t callback;

    void handler(std::string&& s)
    {
        s += "unit:";
        callback(std::move(s));
    }
};

class end_unit
{
public:
    auto get_handler()
    {
        return [this](std::string&& s){ handler(std::move(s)); };
    }
private:
    void handler(std::string&& s)
    {
        s += "end\n";
        std::cout<< s;
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
            s += ":";
            callback(std::move(s));
        }
    }
private:
    callback_t callback;
};

#endif //UNIT_HPP
