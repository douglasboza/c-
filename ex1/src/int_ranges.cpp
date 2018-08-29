
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

    	for (auto i(first); i != last; ++i){
	     	for (auto j(first); (j != last); ++j){
	     		if( pos_preenchida_temp < (pos_preenchida) ){
		     		if( * i == * j ){
		     			teste = 0;
		     		}
		     		pos_preenchida_temp++;
	     		}
	     	}
	     	if(teste == 1){
	     		// std::cout << * i << std::endl;
	     		* (first + pos_preenchida) = * i;
	     		pos_preenchida++;
	     	}
	     	teste = 1;
	     	pos_preenchida_temp = 0;
	     	pos_total++;
     	}
		return first + pos_preenchida;
    }

	int * sort_marbles(int * first , int * last){
		int pos_limit(0); // final do intervalo com as casas pretas

		for (auto i(first); i != last; ++i){
			if(* i == 0){
				std::swap(* (first + pos_limit), * i);
				pos_limit++;
			}
		}
		return first + pos_limit;
	}   

	void partition(int * first , int * last , int * pivot){
		int pos_limit(0); // final do intervalo com os elementos menores que pivot
		int pivot_val = * pivot;
		int teste(0); // teste para verificar se já foi ordenado os elementos menores que pivot

		for (auto i(first); i != last; ++i){
			if(((* i < pivot_val) && (teste == 0)) || ((* i <= pivot_val) && (teste == 1))) {
				std::swap(* (first + pos_limit), * i);
				pos_limit++;
			}
			if((teste == 0) && (i == last - 1)){
				i = first + pos_limit;
				teste = 1;
			}
		}
	} 

	void rotate(int * first, int * n_first, int * last){
		// 

		int cont(1); // contagem enquanto percorre cada elemento do intervalo [first, last}
		int total = std::distance(first, n_first); // tamanho do intervalo que será invertido
		int total2 = std::distance(first, last); // quantidade de elementos do array
		int vezes_rodou(0); // contagem para verificar se chegou no limite de intervalos [ first , last ) rotacionados
		
		// Esse 'for' considera os elementos do intervalo [ first , n_first ) e inverte o valor deles com o intervalo [last - n_first, last}
		for (auto i(n_first - 1); cont <= total; --i){
			std::swap(* i, * (last - cont)); // iverte os valores
			if(vezes_rodou <= (total2 / 2)){ // verfica se ainda restam intervalos de n_first elementos para serem invertidos
				if( cont == total){ // Verifica se inverteu os elementos do intervalo [ first , last ) 
					last = last - total; // Remove os últimos n_first elementos
					i = n_first; // volta o ponteiro para o início do array
					cont = 0; // zera a contagem para percorrer novamente o intervalo [first, last}
				}
				vezes_rodou++; // a cada incremento, significa que foi rotacionado first-1 elementos
			} 
			cont++;
		}
	}


}
