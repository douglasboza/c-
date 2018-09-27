#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/int_ranges.h"


#include <cstdint>
#include <cstring>

namespace graal{

   
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

	// Procura a primeira ocorrência do elemento que satisfaz p no intervalo [first, last)
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

	// Verifica se todos os elementos no intervalo [first, last) satisfazem p
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

	// Verifica se pelo menos um elemento no intervalo [first, last) satisfaz p
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

	// Verifica se nenhum dos elementos no intervalo [first, last) satisfazem p
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

     //Verifica se os elementos no intervalo [first, last) são iguais aos elementos no intervalo [ first2 ; first2 +( last1 - first1 ))
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

     // Verifica se os elementos no intervalo [first, last) são iguais aos elementos no intervalo [ first_d, last_d )
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
	     	}
	     	teste = 1; 
	     	pos_preenchida_temp = 0;
	     	pos_total++;
     	}
		return primeiro + pos_preenchida*size;


    }

    // Reordena os elementos no intervalo [first, last), os elementos que satisfazem p são realocados para o início
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

    // Reordena os elementos na ordem crescente
    void qsort(void* first, size_t count, size_t size, CHAR_sort_comp c){
    	byte *primeiro = static_cast< byte *>( const_cast <void *> (first));
     	byte aux;
	    for(int j = count-1; j >= 1; j--){ // método bubble sort para ordenar os elementos
			for(int i = 0; i < j; i++){
				if(*(primeiro + i*size) > *(primeiro + (i+1)*size)){
					aux = *(primeiro + i*size);
	                *(primeiro + i*size) = *(primeiro + (i+1)*size);
	                *(primeiro + (i+1)*size) = aux;
	            }
	        }
	    }
    }


	

}
