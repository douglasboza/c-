#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {
    using value_type = int;

    /// Negate all integer values in [first;last).
    void negate(value_type * first, value_type * last);
    /*!
     * \brief Copy the content of the range `[first;last)` to another range beginning at `d_first`.
     * \return An iterator point to the element past the last element copied from the source range.
     */
    value_type * copy( const value_type * , const value_type *, value_type*);

    // retorna primeira ocorrência do menor valor no intevalo
    const value_type * min(const value_type *first, const value_type *last);

    /// Returns a pointer to the first occurrency of the smallest element the range.
    // const value_type * min( const value_type *, const value_type * );

    /// Reverse the order of the elements in range `[first;last)`.
    void reverse(value_type * first, value_type * last);

    void scalar_multiplication(value_type * first, value_type * last, value_type num);

    int dot_product(const int * a_first, const int * a_last, const int * b_first);

    int * compact(value_type * first, value_type * last);
    
    // copia dos elementos do intervalor `[first;last)` para o vetor destino, iniciado em d_first
    int * copy(const int * first , const int * last , int * d_first);

    int * unique(int * first , int * last);

}
#endif
