#include "unit.hpp"
#include "pipe.hpp"

int main()
{
    using branch1 = pipe<unit, unit, end_unit>;
    using branch2 = pipe<unit, end_unit>;
    using par = parallel<branch1, branch2, end_unit>;
    auto x = start_unit<par>();
    x();
}
