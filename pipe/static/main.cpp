#include "unit.hpp"
#include "pipe.hpp"

int main()
{
    auto x = start_unit<unit, unit, end_unit>();
    x();
}
