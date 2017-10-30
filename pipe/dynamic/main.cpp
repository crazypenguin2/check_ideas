#include "unit.hpp"
#include "compositor.hpp"

int main()
{
    auto x = pipe<start_unit, unit, unit, end_unit>();
    x();
}

