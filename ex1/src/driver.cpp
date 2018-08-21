#include <iostream> // cout, endl
#include <iterator> // begin, end
#include <sstream>  // ostringstream
#include <algorithm> // for_each
#include "../include/int_ranges.h"

std::string print( const int* first, const int* last )
{
    std::ostringstream oss;

    oss << "[ ";
    std::for_each(first, last, [&](const int & a){ oss << a << " ";} );
    oss << "]";
    return oss.str();
}

int main (void)
{
    int A[]{1,2,3,0,5,6};
    //std::cout << std::begin(A);

    // std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;
    // ir::negate( std::begin(A), std::end(A) );
    // std::cout << ">>> A: " << print( std::begin(A), std::end(A) ) << std::endl;

    auto b = ir::min(std::begin(A), std::end(A) );
    std::cout << *b << std::endl;

    return EXIT_SUCCESS;
}
