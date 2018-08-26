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
    // int A_E[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int A[]{2, 1, 2, 2, 4, 5, 6, 4, 1, 8};

    //std::cout << std::begin(A);

    //std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
    //ir::negate( std::begin(A), std::end(A) );
    //std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

    // auto b = ir::min(std::begin(A), std::end(A) );

    // ir::reverse(std::begin(A), std::end(A) );
    // ir::compact( std::begin(A), std::end(A));

    ir::unique( std::begin(A), std::end(A));

    for (auto i(std::begin(A)); i != std::end(A); ++i){
          std::cout << * i << std::endl; 
    }
    // std::cout << *(std::end(A_E)-1) << std::endl;

    return EXIT_SUCCESS;
}
