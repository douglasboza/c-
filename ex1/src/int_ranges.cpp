
#include "../include/int_ranges.h"
#include <iostream> // cout, endl

namespace ir{

    void negate( value_type * first, value_type * last ){
    	std::cout << *first << std::endl;

        while( first != last )
            *first++ *= -1;
    }

    const value_type *min(const value_type *first, const value_type *last ) {
     	const value_type * a = first;
     	while( first != last ){
			if(*a > *first){
				a = first;
			}
			first++;


     		//std::cout << *a << std::endl;
     	
     	}
     	return a;
    }

}
