#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace graal {
    // using value_type = int;

    using Compare = bool (*)(const void *, const void *);
    using Predicate = bool (*)(const void *);
    using Equal = bool (*)(const void *, const void *);
    using CHAR_sort_comp = bool (*)(const void *, const void *);

    typedef unsigned char byte;


    /// const void *min(const void *first, const void *last, size_t size, Compare cmp);
    /*!
     * \brief Essa função procura a primeira ocorrência do primeiro elemento que satisfaz cmp no intervalo [ first , last )
     * \return Retorna um ponteiro para a primeira ocorrência, caso não exista, retorna last
     */
    const void *min(const void *first, const void *last, size_t size, Compare cmp);


    /// void reverse(void *first,    void * last, size_t size);
    /*!
     * \brief Inverte os elementos no intervalo [ first , last )
     */
    void reverse(void *first, void * last, size_t size);


    /// void * copy(const void * first, const void * last, const void * d_first, size_t size);
    /*!
     * \brief Faz uma cópia dos elementos do intervalor `[first;last)` para o vetor destino iniciado em d_first
     * \return Retorna um ponteiro para a área de memória que foi preenchida com a cópia
     */
    void * copy(const void * first, const void * last, const void * d_first, size_t size);


    /// void * clone(const void * first, const void * last, size_t size);
    /*!
     * \brief Faz uma cópia dos elementos do intervalo `[first;last)` para o vetor alocado dinamicamente
     * \return Retorna um ponteiro para a área de memória que foi alocada e preenchida com o clone do vetor
     */
    void * clone(const void * first, const void * last, size_t size);


    /// const void *find_if(const void * first, const void * last, size_t size, Predicate p);
    /*!
     * \brief Procura a primeira ocorrência do elemento que satisfaz p no intervalo [first, last)
     * \return Retorna um ponteiro para a primeira ocorrência que satisfaz p
     */
    const void *find_if(const void * first, const void * last, size_t size, Predicate p);


    /// const void *find_if(const void * first, const void * last, size_t size, Predicate p);
    /*!
     * \brief Procura a primeira ocorrência do elemento que satisfaz p no intervalo [first, last)
     * \return Retorna um ponteiro para a primeira ocorrência que satisfaz p
     */
    // Retorna um ponteiro para a primeira ocorrênci que satisfaz eq passando o value e a oocorrência no intervalo
    const void *find(const void* first, const void * last, size_t size, const void* value, Equal eq);


    /// bool all_of(const void* first, const void* last, size_t size, Predicate p);
    /*!
     * \brief Verifica se todos os elementos no intervalo [first, last) satisfazem p
     * \return Retorna true se todos os elementos satifazem p, caso contrário retorna false
     */
    bool all_of(const void* first, const void* last, size_t size, Predicate p);


    /// bool any_of(const void* first, const void* last, size_t size, Predicate p);
    /*!
     * \brief Verifica se pelo menos um elemento no intervalo [first, last) satisfaz p
     * \return Retorna true se pelo menos um elemento satisfaz p, caso contrário retorna false
     */
    bool any_of(const void* first, const void* last, size_t size, Predicate p);


    /// bool none_of(const void* first, const void* last, size_t size, Predicate p);
    /*!
     * \brief Verifica se nenhum dos elementos no intervalo [first, last) satisfazem p
     * \return Retorna false se pelo menos um elemento satisfaz p, caso contrário retorna true
     */
    bool none_of(const void* first, const void* last, size_t size, Predicate p);


    /// bool equal(const void* first, const void* last, const void* first_d, size_t size, Equal eq);
    /*!
     * \brief Verifica se os elementos no intervalo [first, last) são iguais 
     *        aos elementos no intervalo [ first2 ; first2 +( last1 - first1 ))
     * \return Retorna true se os elementos forem todos iguais. Retorna falso, caso contrário.
     */
    bool equal(const void* first, const void* last, const void* first_d, size_t size, Equal eq);


    /// bool equal(const void* first, const void* last, const void* first_d, const void* last_d, size_t size, Equal eq);
    /*!
     * \brief Verifica se os elementos no intervalo [first, last) são iguais 
     *        aos elementos no intervalo [ first_d, last_d )
     * \return Retorna true se os elementos forem todos iguais. Retorna falso, caso contrário.
     */
    bool equal(const void* first, const void* last, const void* first_d, const void* last_d, size_t size, Equal eq);


    /// void * unique(void *first, void * last, size_t size, Equal eq);
    /*!
     * \brief Reordena os elementos no intervalo [first, last) de modo que os elementos não repetidos fiquem no iníco
     * \return Um ponteiro para o último elemento do intervalo com elementos únicos
     */
    void * unique(void *first, void * last, size_t size, Equal eq);


    /// void * partition (void* first, void * last, size_t size, Predicate p);
    /*!
     * \brief Reordena os elementos no intervalo [first, last), os elementos que satisfazem p são realocados para o início
     * \return Um ponteiro o primeiro elemento que retorna false em p
     */
    void * partition (void* first, void * last, size_t size, Predicate p);


    /// void qsort (void* first, size_t count, size_t size, CHAR_sort_comp c);
    /*!
     * \brief Reordena os elementos na ordem crescente
     */
    void qsort (void* first, size_t count, size_t size, CHAR_sort_comp c);



}
#endif
