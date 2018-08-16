
#include "../include/int_ranges.h"

namespace ir
{
    void negate( value_type * first, value_type * last )
    {
        while( first != last )
            *first++ *= -1;
    }

}
