#include "unit.hpp"
#include "pipe.hpp"

int main()
{
    auto p = make_pipe(start_unit<uint64_t>{}, unit<uint64_t>{}, unit<uint64_t>{}, end_unit<uint64_t>{});
    p();
}
