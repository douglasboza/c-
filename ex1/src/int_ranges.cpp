
#include "../include/int_ranges.h"
#include <iostream> // cout, endl

namespace ir{

    void negate( value_type * first, value_type * last ){
    	std::cout << *first << std::endl;

        while( first != last )
            *first++ *= -1;
    }

    const value_type *min(const value_type *first, const value_type *last ) {
     	const value_type * min = first;
     	while( first != last ){
			if(*min > *first){
				min = first;
			}
			first++;     	
     	}
     	return min;
    }

    void reverse(value_type *first, value_type *last ) {
    	int j = 2;
     	
     	for (auto i( first+1 ); i != last-1; ++i){
     		std::swap(*i, *(last-j));
     		j = j + 1;
     	}

    }

    void scalar_multiplication( value_type * first, value_type * last, value_type num ){
     	for (auto i( first ); i != last; ++i){
     		*i *= num;
     	}
    }

}
