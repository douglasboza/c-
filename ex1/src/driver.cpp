#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/int_ranges.h"

std::string print( const int* first, const int* last ){
    std::ostringstream oss;

    oss << "[ ";
    std::for_each(first, last, [&](const int & a){ oss << a << " ";} );
    oss << "]";
    return oss.str();
}

int main (void){
    // int A[]{-2, -8, 2, 7, -3, 10, 1, 0, -3, 7};
    // int A[]{0, 0, 1, 1, 0, 1, 0, 1, 0, 0};
    // int A[]{-5, 7, 10, 7, 8, 9, 1, 7, -2, 3};
    // int A[] = {1, 2};
    // int a = 3;

    // int A[]{0, 1};
    // int *a = ir::sort_marbles(std::begin(A), std::end(A));

    // ir::value_type A_E[]{2, 1, 4, 5, 6, 8};

    // int A[]{2, 1, 2, 2, 4, 5, 6, 4, 1, 8};

    //std::cout << std::begin(A);

    //std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
    //ir::negate( std::begin(A), std::end(A) );
    //std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

    // auto b = ir::min(std::begin(A), std::end(A) );

    // ir::reverse(std::begin(A), std::end(A) );
    // ir::compact( std::begin(A), std::end(A));
    // std::cout << *( std::begin(A) + 3) << std::endl;

    // ir::partition( std::begin(A), std::end(A), std::begin(A) + 3);

    // ir::rotate(std::begin(A), std::begin(A) + 1, std::end(A));
    // ir::rotate(std::begin(A), std::begin(A) + 2 , std::end(A) - 2);
    // ir::rotate(std::begin(A), std::begin(A) + 2 , std::end(A) - 4);
            // rotate(first, n_first, last - 2);

    // for (auto i(std::begin(A)); i != std::end(A); ++i){
    //       std::cout << * a << " "; 
    // }
    // [ −5, 3, −2, 1, 7, 7, 7, 9, 8, 10 ]

    // int A[]{ 1, 2, 3, 4, 5 };
    // // ir::value_type A_E[]{ 1, 4, 3, 2, 5};
    //     ir::reverse(std::begin(A), std::end(A) );
    // // ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
    // // ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );

    // for (auto i(std::begin(A)); i != std::end(A); ++i){
    //       // std::cout << * i << " "; 
    // }


    return EXIT_SUCCESS;
}
