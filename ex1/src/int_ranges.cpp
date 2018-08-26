
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

    int dot_product(const int * a_first, const int * a_last, const int * b_first){
    	int ret(0);

    	for (auto i(a_first); i != a_last; ++i){
     		ret = ret + (* i) * (* b_first);
     		b_first++;
     	}

     	return ret;
    }

    int * compact( value_type * first, value_type * last ){
    	value_type pos_atual(0);

    	for (auto i(first); i != last; ++i){
     		if( * i > 0 ){
     			// std::cout << * i << std::endl;
     			* (first + pos_atual) = * i;
     			pos_atual++;
     		}

     	}
     	return first + pos_atual;
    }

    int * copy ( const int * first , const int * last , int * d_destino ){
		// int pos_atual(0);

    	for (auto i(first); i != last; ++i){
     		* d_destino = * i;
    		// std::cout << * d_destino << std::endl;
     		d_destino++;
     	}

     	return d_destino;
    }

    int * unique(int * first , int * last){
    	int pos_total(0);
    	int pos_preenchida(0);
    	int pos_preenchida_temp(0);
    	int teste(1);

    	for (auto i(first); i != last; ++i){ // 1
	     	for (auto j(first); (j != last); ++j){
	     		if( pos_preenchida_temp < (pos_preenchida) ){
		     		if( * i == * j ){
		     			teste = 0;
		     		}
		     		pos_preenchida_temp++;
	     		}
	     	}
	     	if(teste == 1){
	     		std::cout << * i << std::endl;
	     		* (first + pos_preenchida) = * i;
	     		pos_preenchida++;
	     	}
	     	teste = 1;
	     	pos_preenchida_temp = 0;
	     	pos_total++;
     	}
     	std::cout << "\n\n\n" << std::endl;
     	return NULL;
    }
    	     
			//  int A[]{2, 1, 2, 2, 4, 5, 6, 4, 1, 8};


}
