
#include "../include/int_ranges.h"
#include <iostream> // cout, endl

namespace ir{

    void negate(value_type * first, value_type * last){
       
        while( first != last ){ // percorre cada elemento do array e inverte o valor
            *first++ *= -1; 
        }

    }

    // Retorna um ponteiro para a primeira ocorrência do menorelemento no intervalo [ first , last )
    const int * min(const int * first, const int * last) {
     	const value_type * min = first; // Define o primeiro elemento para sendo o menor
     	
     	while( first != last ){ // Percorre o array
			if(*min > *first){ // Verifica se os próximo elemento é menor que o min
				min = first;   // Aponta o min para o novo elemento menor encontrado
			}
			first++;     	// Próxima posição do ponteiro no array
     	}

     	return min;   // Retorna a posição do enor elemento no intervalo
    }

    // Inverte a ordem dos elementos no intervalo [ first , last ) definido sobre um vetor de inteiros.
    void reverse(value_type * first, value_type * last) {
    	int j = 1;	// Para obter a posição do último ponteiro
     	
     	for (auto i(first); i != (first + (std::distance(first, last) / 2) ); ++i){ // percorre a metade dos elementos
     		std::swap(* i, * (last - j)); // inverte o valor dos elementos da primeira metade com a segunda metade
     		j++;
     	}

    }

    // multiplica o inteiro 'num' passado por parâmetro por todos os elementos no intervalo [ first , last )
    void scalar_multiplication( value_type * first, value_type * last, value_type num ){
     	for (auto i( first ); i != last; ++i){ // Percorre cada elemento do intervalo
     		*i *= num;  // Multiplica o valor do elemento pelo num
     	}
    }

    // Calcula e retorna o produto escalar entre 2 vetores
    int dot_product(const int * a_first, const int * a_last, const int * b_first){
    	int ret(0);  // Retorno

    	for (auto i(a_first); i != a_last; ++i){
     		ret = ret + (* i) * (* b_first); // Multiplica os elementos na mesma posição dos intervalor e adiciona no ret
     		b_first++; // Próxima posição do intervalo 
     	}
   
     	return ret;
    }

    // Compacta os elementos no intervalo [ first , last )
    int * compact(value_type * first, value_type * last){
    	value_type pos_atual(0); // Posição que foi preenchida

    	for (auto i(first); i != last; ++i){ // Percorre cada elemento do intervalo
     		if( * i > 0 ){ // Verifica se o elemento é maior que zero
     			* (first + pos_atual) = * i; // Copia o valor desse elemento para o pos_atual do intervalo
     			pos_atual++; // Próxima posição para ser preenchida
     		}
     	}

     	return first + pos_atual; // Retorna até quais posições foram preenchidas
    }

    // Copia dos elementos do intervalor `[first;last)` para o vetor destino, iniciado em d_destino
    int * copy(const int * first, const int * last, int * d_destino){
	 	for (auto i(first); i != last; ++i){ // Percorre os elementos do intervaçp
     		* d_destino = * i;	// Copia cada elemento para o novo intervalo
     		d_destino++; // Move o ponteiro do novo intervalo
     	}
     	return d_destino;
    }

    // Elimina repetições de elementos no intervalo [ first , last ),
    int * unique(int * first , int * last){
    	int pos_total(0); // Posição para percorrer o intervalo [ first , last )
    	int pos_preenchida(0); // Posição que foi preenchida com um elemento não repetido anteriormente
    	int pos_preenchida_temp(0); // Posição temporária para percorre os elementos não repetidos já preenchidos
    	int teste(1); // Teste para verificar se o elemente já foi adicionado do intervalo novo

    	for (auto i(first); i != last; ++i){ // Percorre os elementos do intervalo [first, last)
	     	for (auto j(first); j != last ; ++j){ // Percorre os elementos já preenchidos
	     		if(pos_preenchida_temp < pos_preenchida){
		     		if(* i == * j){
		     			teste = 0;
		     		}
		     		pos_preenchida_temp++;
	     		}else{
	     			break; // final dos elementos já preenchidos
	     		}
	     	}

	     	if(teste == 1){ // Se teste == 1, então o elemento não foi preenchido no intervalo até ele
	     		* (first + pos_preenchida) = * i; // Preenche com o elemento que não foi preenchido ainda
	     		pos_preenchida++; // Próxima posição
	     		// std::cout << * i << std::endl;
	     	}
	     	teste = 1; 
	     	pos_preenchida_temp = 0;
	     	pos_total++;
     	}
		return first + pos_preenchida; // retorna até qual posição foi preenchida com elementos não repetidos anteriormente.
    }

	int * sort_marbles(int * first , int * last){
		int pos_limit(0); // final do intervalo com as casas pretas

		for (auto i(first); i != last; ++i){ // Percorre os elementos do array
			if(* i == 0){ // Caso o elemento seja preto
				std::swap(* (first + pos_limit), * i); // Inverte a posição do elemento preto com o próxima elemento do intervalo inicial com elementos pretos 
				pos_limit++; // Próxima elemento preto para ser preenchido
			}
		}
		return first + pos_limit; // Retorna o ponteido depois do último elemento preto
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
	// Função que realiza uma rotação à esquerda nos elementos do intervalo [ n_first , last )

		int cont(1); // contagem enquanto percorre cada elemento do intervalo [first, last}
		int total = std::distance(first, n_first); // tamanho do intervalo que será invertido
		int total2 = std::distance(first, last); // quantidade de elementos do array
		int vezes_rodou(0); // contagem para verificar se chegou no limite de intervalos [ first , last ) rotacionados
		if(total2 == 2){ 
			vezes_rodou = 10; // Para não resetar o 'for', caso só tenham dois elementos no array
		}
		
		// Esse 'for' considera os elementos do intervalo [ first , n_first ) e inverte o valor deles com o intervalo [last - n_first, last}
		for (auto i(n_first - 1); cont <= total; --i){
			// std::cout << (total2 / 2) << " vira "<< * (last - cont) << std::endl;
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
