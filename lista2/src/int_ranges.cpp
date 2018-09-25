#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/int_ranges.h"


#include <cstdint>
#include <cstring>

namespace graal{

    // void negate(value_type * first, value_type * last){
       
    //     while( first != last ){ // percorre cada elemento do array e inverte o valor
    //         *first++ *= -1; 
    //     }

    // }


    // Retorna um ponteiro para a primeira ocorrência do menorelemento no intervalo [ first , last )
   //  const int * min(const int * first, const int * last) {
   //   	const value_type * min = first; // Define o primeiro elemento para sendo o menor
     	
   //   	while( first != last ){ // Percorre o array
			// if(*min > *first){ // Verifica se os próximo elemento é menor que o min
			// 	min = first;   // Aponta o min para o novo elemento menor encontrado
			// }
			// first++;     	// Próxima posição do ponteiro no array
   //   	}

   //   	return min;   // Retorna a posição do enor elemento no intervalo
   //  }

	// Retorna um ponteiro para a primeira ocorrência do menorelemento no intervalo [ first , last )
	const void *min(const void *first, const void *last, size_t size, Compare cmp){
	
     	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *menor = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
     	
     	while(primeiro != ultimo){ // Percorre o array
			if(cmp(primeiro, menor)){ // Verifica se o próximo elemento é menor que o "menor"		 
				menor = primeiro; // aponta o "menor" para o novo elemento menor
			}
			primeiro += size; // Próxima posição do ponteiro no array
     	}

     	return menor; // Retorna a posição do menor elemento no intervalo
	}



	// Inverte a ordem dos elementos no intervalo [ first , last ) definido sobre um vetor de inteiros.
	void reverse(void *first, void * last, size_t size){
   		byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
     	// byte *temp;
     	// temp = (byte*) malloc (size);

     	unsigned int total = std::distance(primeiro, ultimo)/size;
     	for (unsigned int i = 0; i < total/2; ++i){ // percorre cada elemento até a metade do vetor
     		ultimo -= size; // elemento anterior começando do último
     		if(i != 0) primeiro += size; // próximo elemento
     		std::swap(*ultimo, *primeiro);
     	 	// temp = *ultimo;      // realiza a troca dos valores
	     	// *ultimo = *primeiro;
	     	// *primeiro = temp;
		}
		std::cout << "===== passou final ==== " << std::endl; 
	}

	// Copia dos elementos do intervalor `[first;last)` para o vetor destino, iniciado em d_first
	void * copy(const void * first, const void * last, const void * d_first, size_t size){

		byte *primeiro = static_cast< byte *>(const_cast <void *> (first));
		byte *primeiro_destino = static_cast< byte *>(const_cast <void *> (d_first));
		
		unsigned int total = std::distance(primeiro, static_cast< byte *>(const_cast <void *> (last)))/size;


		for (unsigned int i = 0; i < total; ++i){ // percorre cada elemento até a metade do vetor
     		if(i != 0) primeiro += size; // próximo elemento
   	     	*primeiro_destino = *primeiro; // copia o elemento para o vetor destino
			primeiro_destino += size;
		}
     	return primeiro;
	}

	// Copia dos elementos do intervalor `[first;last)` para o vetor destino, iniciado em d_first
	void * clone(const void * first, const void * last, size_t size){
		const void* d_first;
		byte *primeiro = static_cast< byte *>(const_cast <void *> (first));
		byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
     	unsigned int total = std::distance(primeiro, ultimo)/size;

		d_first = new char[total*size];
		byte *primeiro_destino = static_cast< byte *>(const_cast <void *> (d_first));

		for (unsigned int i = 0; i < total; ++i){ // percorre cada elemento até a metade do vetor
     		if(i != 0){
     			primeiro += size;
				primeiro_destino += size;
     		}

   	     	*primeiro_destino = *primeiro;
     		// std::cout << *((const int *) primeiro_destino) << std::endl;  
		}	

     	return primeiro_destino - total*size + 1*size;
	}


	const void *find_if(const void * first, const void * last, size_t size, Predicate p){
		byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *posicao = static_cast< byte *>( const_cast <void *> (last)); 
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last)); 
     	
     	while(primeiro != ultimo){ // Percorre o array
			if(p(primeiro)){ // Verifica se o próximo elemento satisfaz p 
				posicao = primeiro; // aponta a posicao para o novo elemento
				return posicao;
			}
			primeiro += size; // Próxima posição do ponteiro no array
     	}

     	return posicao; // Retorna a posição do primeiro elemento que satisfaz p ou para last se nenhum elemento satisfaz p
	}

	// Retorna um ponteiro para a primeira ocorrênci que satisfaz eq passando o value e a oocorrência no intervalo
	const void *find(const void* first, const void * last, size_t size, const void* value, Equal eq){
		byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *posicao = static_cast< byte *>( const_cast <void *> (last)); 
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last)); 
     	
     	while(primeiro != ultimo){ // Percorre o array
			if(eq(primeiro, value)){ // Verifica se o próximo elemento satisfaz p 
				posicao = primeiro; // aponta a posicao para o novo elemento
				return posicao;
			}
			primeiro += size; // Próxima posição do ponteiro no array
     	}
     	return posicao; // Retorna a posição do primeiro elemento que satisfaz p ou para last se nenhum elemento satisfaz p
	}

	
    bool all_of(const void* first, const void* last, size_t size, Predicate p){
		byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last)); 

     	while(primeiro != ultimo){ // Percorre o array
			if(!p(primeiro)){ // Verifica se o próximo elemento satisfaz p 
				return false;	
			}
			primeiro += size; // Próxima posição do ponteiro no array
     	}
     	return true; // Retorna a posição do primeiro elemento que satisfaz p ou para last se nenhum elemento satisfaz p
	}

    bool any_of(const void* first, const void* last, size_t size, Predicate p){
		byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last)); 
     	
     	while(primeiro != ultimo){ // Percorre o array
			if(p(primeiro)){ // Verifica se o próximo elemento satisfaz p 
				return true;
			}
			primeiro += size; 
     	}
     	return false; 
	}

    bool none_of(const void* first, const void* last, size_t size, Predicate p){
		byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last)); 
     	
     	while(primeiro != ultimo){ // Percorre o array
			if(p(primeiro)){ // Verifica se o próximo elemento satisfaz p 
				return false;
			}
			primeiro += size; // Próxima posição do ponteiro no array
     	}
     	return true; 
     }

     bool equal(const void* first, const void* last, const void* first_d, size_t size, Equal eq){
     	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *segundo = static_cast< byte *>( const_cast <void *> (first_d));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
     	
     	while(primeiro != ultimo){ // Percorre o array
			if(!eq(primeiro, segundo)){ // Verifica se o próximo elemento é menor que o "menor"		 
				return false; // retorna false se a comparação retornar false
			}
			segundo += size;
			primeiro += size; // Próxima posição do ponteiro no array
     	}

     	return true;
     }


     bool equal(const void* first, const void* last, const void* first_d, const void* last_d, size_t size, Equal eq){
     	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
     	byte *segundo = static_cast< byte *>( const_cast <void *> (first_d));
     	byte *segundo_last = static_cast< byte *>( const_cast <void *> (last_d));
     	
     	while((primeiro != ultimo) && (segundo != segundo_last)){ // Percorre o array
			if(!eq(primeiro, segundo)){ // Verifica se o próximo elemento é menor que o "menor"		 
				return false;
			}
			segundo += size;
			primeiro += size; // Próxima posição do ponteiro no array
     	}
     	if((primeiro == ultimo) && (segundo == segundo_last)){ // retorna true e a comparação não retornou false e são de mesmo tamanho
     		return true;
     	}

     	return false;

     }

    // Elimina repetições de elementos no intervalo [ first , last ),
    void * unique(void *first, void * last, size_t size, Equal eq){
    	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	// byte *intervalo_unique = static_cast< byte *>( const_cast <void *> (first));
     	byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
 
    	int pos_total(0); // Posição para percorrer o intervalo [ first , last )
    	int pos_preenchida(0); // Posição que foi preenchida com um elemento não repetido anteriormente
    	int pos_preenchida_temp(0); // Posição temporária para percorre os elementos não repetidos já preenchidos
    	int teste(1); // Teste para verificar se o elemente já foi adicionado do intervalo novo

    	for (auto i(primeiro); i != ultimo; i=i+size){ // Percorre os elementos do intervalo [first, last)
	     	
	     	

	     	for (auto j(primeiro); j != ultimo; j=j+size){ // Percorre os elementos já preenchidos
	     		if(pos_preenchida_temp < pos_preenchida){
		     		if(eq(i, j)){
		     			teste = 0;
		     		}
		     		pos_preenchida_temp++;
	     		}else{
	     			break; // final dos elementos já preenchidos
	     		}
	     	}

	     	if(teste == 1){ // Se teste == 1, então o elemento não foi preenchido no intervalo até ele
	     		* (primeiro + pos_preenchida*size) = * i; // Preenche com o elemento que não foi preenchido ainda
	     		pos_preenchida++; // Próxima posição
	     		// std::cout << * i << std::endl;
	     	}
	     	teste = 1; 
	     	pos_preenchida_temp = 0;
	     	pos_total++;
     	}
		return primeiro + pos_preenchida*size; // r


    }

    void * partition(void * first, void * last, size_t size, Predicate p){
    	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
    	byte *ultimo = static_cast< byte *>( const_cast <void *> (last));
    	int pos_limit(0); // final do intervalo com os elementos menores que pivot

		for (auto i(primeiro); i != ultimo; i += size){
			if(p(i)){ 
				std::swap(* (primeiro + pos_limit*size), * i); 
				pos_limit++; // Ṕróxima posição do ponteiro que define os elementos já preenchidos corretamente
			}
		}
		return primeiro + pos_limit * size;
    }	


    void qsort(void* first, size_t count, size_t size, CHAR_sort_comp c){
    	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte aux;
	    for(int j = count-1; j >= 1; j--){
			for(int i = 0; i < j; i++){
				if(*(primeiro + i*size) > *(primeiro + (i+1)*size)){
					aux = *(primeiro + i*size);
	                *(primeiro + i*size) = *(primeiro + (i+1)*size);
	                *(primeiro + (i+1)*size) = aux;
	            }
	        }
	    }
    }


	// Rearranja os elementos do intervalo [ first , last ) com base em no valor apontado por pivot
	// void partition(int * first , int * last , int * pivot){
	// 	int pos_limit(0); // final do intervalo com os elementos menores que pivot
	// 	int pivot_val = * pivot;
	// 	int teste(0); // teste para verificar se já foi ordenado os elementos menores que pivot

	// 	for (auto i(first); i != last; ++i){
	// 		if(((* i < pivot_val) && (teste == 0)) || ((* i <= pivot_val) && (teste == 1))) { 
	// 			// Primeiro será feito a troca dos elementos menores que pivot
	// 			// Depois será feito a troca dos elementos iguais a pivot
	// 			// Por consequência, os elementos maiores que pivot ficarão no final
	// 			std::swap(* (first + pos_limit), * i); 
	// 			pos_limit++; // Ṕróxima posição do ponteiro que define os elementos já preenchidos corretamente
	// 		}
	// 		if((teste == 0) && (i == last - 1)){ 
	// 			// Ao chegar no final do primeiro loop, o ponteiro volta para o final dos elementos menores que pivot
	// 			// Seta teste como 1 para preencher os elementos iguais a pivot
	// 			i = first + pos_limit;
	// 			teste = 1;
	// 		}
	// 	}
	// } 



 //    int * copy(const int * first, const int * last, int * d_destino){
	//  	for (auto i(first); i != last; ++i){ // Percorre os elementos do intervaçp
 //     		* d_destino = * i;	// Copia cada elemento para o novo intervalo
 //     		d_destino++; // Move o ponteiro do novo intervalo
 //     	}
 //     	return d_destino;
 //    }


 //    // multiplica o inteiro 'num' passado por parâmetro por todos os elementos no intervalo [ first , last )
 //    void scalar_multiplication( value_type * first, value_type * last, value_type num ){
 //     	for (auto i( first ); i != last; ++i){ // Percorre cada elemento do intervalo
 //     		*i *= num;  // Multiplica o valor do elemento pelo num
 //     	}
 //    }

 //    // Calcula e retorna o produto escalar entre 2 vetores
 //    int dot_product(const int * a_first, const int * a_last, const int * b_first){
 //    	int ret(0);  // Retorno

 //    	for (auto i(a_first); i != a_last; ++i){
 //     		ret = ret + (* i) * (* b_first); // Multiplica os elementos na mesma posição dos intervalor e adiciona no ret
 //     		b_first++; // Próxima posição do intervalo 
 //     	}
   
 //     	return ret;
 //    }

 //    // Compacta os elementos no intervalo [ first , last )
 //    int * compact(value_type * first, value_type * last){
 //    	value_type pos_atual(0); // Posição que foi preenchida

 //    	for (auto i(first); i != last; ++i){ // Percorre cada elemento do intervalo
 //     		if( * i > 0 ){ // Verifica se o elemento é maior que zero
 //     			* (first + pos_atual) = * i; // Copia o valor desse elemento para o pos_atual do intervalo
 //     			pos_atual++; // Próxima posição para ser preenchida
 //     		}
 //     	}

 //     	return first + pos_atual; // Retorna até quais posições foram preenchidas
 //    }



 //    // Elimina repetições de elementos no intervalo [ first , last ),
 //    int * unique(int * first , int * last){
 //    	int pos_total(0); // Posição para percorrer o intervalo [ first , last )
 //    	int pos_preenchida(0); // Posição que foi preenchida com um elemento não repetido anteriormente
 //    	int pos_preenchida_temp(0); // Posição temporária para percorre os elementos não repetidos já preenchidos
 //    	int teste(1); // Teste para verificar se o elemente já foi adicionado do intervalo novo

 //    	for (auto i(first); i != last; ++i){ // Percorre os elementos do intervalo [first, last)
	//      	for (auto j(first); j != last ; ++j){ // Percorre os elementos já preenchidos
	//      		if(pos_preenchida_temp < pos_preenchida){
	// 	     		if(* i == * j){
	// 	     			teste = 0;
	// 	     		}
	// 	     		pos_preenchida_temp++;
	//      		}else{
	//      			break; // final dos elementos já preenchidos
	//      		}
	//      	}

	//      	if(teste == 1){ // Se teste == 1, então o elemento não foi preenchido no intervalo até ele
	//      		* (first + pos_preenchida) = * i; // Preenche com o elemento que não foi preenchido ainda
	//      		pos_preenchida++; // Próxima posição
	//      		// std::cout << * i << std::endl;
	//      	}
	//      	teste = 1; 
	//      	pos_preenchida_temp = 0;
	//      	pos_total++;
 //     	}
	// 	return first + pos_preenchida; // retorna até qual posição foi preenchida com elementos não repetidos anteriormente.
 //    }

 //    // Rearranja os elementos do intervalo usando apenas a operação de troca
	// int * sort_marbles(int * first , int * last){
	// 	int pos_limit(0); // final do intervalo com as casas pretas

	// 	for (auto i(first); i != last; ++i){ // Percorre os elementos do array
	// 		if(* i == 0){ // Caso o elemento seja preto
	// 			std::swap(* (first + pos_limit), * i); // Inverte a posição do elemento preto com o próxima elemento do intervalo inicial com elementos pretos 
	// 			pos_limit++; // Próxima elemento preto para ser preenchido
	// 		}
	// 	}
	// 	return first + pos_limit; // Retorna o ponteido depois do último elemento preto
	// }   

	// // Rearranja os elementos do intervalo [ first , last ) com base em no valor apontado por pivot
	// void partition(int * first , int * last , int * pivot){
	// 	int pos_limit(0); // final do intervalo com os elementos menores que pivot
	// 	int pivot_val = * pivot;
	// 	int teste(0); // teste para verificar se já foi ordenado os elementos menores que pivot

	// 	for (auto i(first); i != last; ++i){
	// 		if(((* i < pivot_val) && (teste == 0)) || ((* i <= pivot_val) && (teste == 1))) { 
	// 			// Primeiro será feito a troca dos elementos menores que pivot
	// 			// Depois será feito a troca dos elementos iguais a pivot
	// 			// Por consequência, os elementos maiores que pivot ficarão no final
	// 			std::swap(* (first + pos_limit), * i); 
	// 			pos_limit++; // Ṕróxima posição do ponteiro que define os elementos já preenchidos corretamente
	// 		}
	// 		if((teste == 0) && (i == last - 1)){ 
	// 			// Ao chegar no final do primeiro loop, o ponteiro volta para o final dos elementos menores que pivot
	// 			// Seta teste como 1 para preencher os elementos iguais a pivot
	// 			i = first + pos_limit;
	// 			teste = 1;
	// 		}
	// 	}
	// } 

	// void rotate(int * first, int * n_first, int * last){
	// // Função que realiza uma rotação à esquerda nos elementos do intervalo [ n_first , last )

	// 	int cont(1); // contagem enquanto percorre cada elemento do intervalo [first, last}
	// 	int total = std::distance(first, n_first); // tamanho do intervalo que será invertido
	// 	int total2 = std::distance(first, last); // quantidade de elementos do array
	// 	int vezes_rodou(0); // contagem para verificar se chegou no limite de intervalos [ first , last ) rotacionados
	// 	if(total2 == 2){ 
	// 		vezes_rodou = 10; // Para não resetar o 'for', caso só tenham dois elementos no array
	// 	}
		
	// 	// Esse 'for' considera os elementos do intervalo [ first , n_first ) e inverte o valor deles com o intervalo [last - n_first, last}
	// 	for (auto i(n_first - 1); cont <= total; --i){
	// 		// std::cout << (total2 / 2) << " vira "<< * (last - cont) << std::endl;
	// 		std::swap(* i, * (last - cont)); // iverte os valores
	// 		if(vezes_rodou <= (total2 / 2)){ // verfica se ainda restam intervalos de n_first elementos para serem invertidos
	// 			if( cont == total){ // Verifica se inverteu os elementos do intervalo [ first , last ) 
	// 				last = last - total; // Remove os últimos n_first elementos
	// 				i = n_first; // volta o ponteiro para o início do array
	// 				cont = 0; // zera a contagem para percorrer novamente o intervalo [first, last}
	// 			}
	// 			vezes_rodou++; // a cada incremento, significa que foi rotacionado first-1 elementos
	// 		} 
	// 		cont++;
	// 	}
	// }


}
