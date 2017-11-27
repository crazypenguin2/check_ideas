#include "unit.hpp"
#include "pipe.hpp"

int main()
{
    auto p = make_pipe(start_unit_t{}, unit_t{}, unit_t{}, end_unit_t{});
    p();
}
