#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace graal {
    // using value_type = int;

    using Compare = bool (*)(const void *, const void *);
    using Predicate = bool (*)(const void *);
    using Equal = bool (*)(const void *, const void *);

    typedef unsigned char byte;

    /// Negate all integer values in [first;last).
    // void negate(value_type * first, value_type * last);
    /*!
     * \brief Copy the content of the range `[first;last)` to another range beginning at `d_first`.
     * \return An iterator point to the element past the last element copied from the source range.
     */

    /// Retorna um ponteiro para a primeira ocorrência do menorelemento no intervalo [ first , last )
    // const int * min(const int *first, const int *last);
    const void *min(const void *first, const void *last, size_t size, Compare cmp);

    /// Reverse the order of the elements in range `[first;last)`.
    // void reverse(value_type * first, value_type * last);
    void reverse(void *first, void * last, size_t size);

    // copia dos elementos do intervalor `[first;last)` para o vetor destino, iniciado em d_first
    void * copy(const void * first, const void * last, const void * d_first, size_t size);

    // copia dos elementos do intervalor `[first;last)` para o vetor destino, iniciado em d_first
    void * clone(const void * first, const void * last, size_t size);

    // Procura  primeira ocorrência do elemento que satisfaz p no intervalo [first, last)
    const void *find_if(const void * first, const void * last, size_t size, Predicate p);

    // Retorna um ponteiro para a primeira ocorrênci que satisfaz eq passando o value e a oocorrência no intervalo
    const void *find(const void* first, const void * last, size_t size, const void* value, Equal eq);

    bool all_of(const void* first, const void* last, size_t size, Predicate p);
    bool any_of(const void* first, const void* last, size_t size, Predicate p);
    bool none_of(const void* first, const void* last, size_t size, Predicate p);

/*

    // Multiplica o inteiro 'num' passado por parâmetro por todos os elementos no intervalo [ first , last )
    void scalar_multiplication(value_type * first, value_type * last, value_type num);

    // Calcula e retorna o produto escalar entre 2 vetores
    int dot_product(const int * a_first, const int * a_last, const int * b_first);

    // Compacta os elementos no intervalo [ first , last )
    int * compact(value_type * first, value_type * last);
    // Retorna um ponteiro para o elemento imediatamente posterior ao último elemento compactado que permanecerá no intervalo. 
    //  O processo move para o início do intervalo todos os elementos positivos e não nulos, mantendo a ordem relativa entre os elementos originais. 
    
    

    // Elimina repetições de elementos no intervalo [ first , last ),
    int * unique(int * first , int * last);
    // Retorna um ponteiro após-o-final do intervalo resultante.

    // Rearranja os elementos do intervalo usando apenas a operação de troca
    int * sort_marbles(int * first , int * last);

    // Rearranja os elementos do intervalo [ first , last ) com base em no valor apontado por pivot
    void partition(int * first , int * last , int * pivot);

    // rotaciona para a esquerda os elementos do intervalo
    void rotate(int * first, int * n_first, int * last);
    */

}
#endif
