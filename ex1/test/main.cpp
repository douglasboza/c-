#include <iterator> // begin(), end()

#include "gtest/gtest.h"
#include "../include/int_ranges.h"
#include <iostream> // cout, endl

using namespace ir;

TEST(IntRange, NegateBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ -1, -2, -3, -4, -5 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}

TEST(IntRange, NegateZeros){
    ir::value_type A[]{ 0, 0, 0, 0, 0 };
    ir::value_type A_E[]{ 0, 0, 0, 0, 0 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}
TEST(IntRange, NegateMixed){
    ir::value_type A[]{ 0, -2, 1, -3, 0 };
    ir::value_type A_E[]{ 0, 2, -1, 3, 0 };

    auto len_before{ std::distance( std::begin(A), std::end(A) ) };
    ir::negate( std::begin(A), std::end(A) );
    auto len_after{ std::distance( std::begin(A), std::end(A) ) };
    ASSERT_EQ( len_before, len_after );
    ASSERT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E) ) );
}


TEST(IntRange, MinBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E = 1;
    auto * P_E = & A[0];
    auto len_min(ir::min( std::begin(A), std::end(A) ));
    ASSERT_EQ( *len_min, A_E );
    ASSERT_EQ( len_min, P_E );
}

TEST(IntRange, MinOne){
    ir::value_type A[]{1};
    ir::value_type A_E = 1;
    auto * P_E = & A[0];
    auto len_min(ir::min( std::begin(A), std::end(A) ));
    ASSERT_EQ( *len_min, A_E );
    ASSERT_EQ( len_min, P_E );
}

TEST(IntRange, MinLast){
    ir::value_type A[]{9, 8, 3, 2};
    ir::value_type A_E = 2;
    auto * P_E = & A[3];
    auto len_min(ir::min( std::begin(A), std::end(A) ));
    ASSERT_EQ( *len_min, A_E );
    ASSERT_EQ( len_min, P_E );
}

TEST(IntRange, ReverseBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ 1, 4, 3, 2, 5};
    ir::reverse( std::begin(A), std::end(A) );
    ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
    ir::reverse( std::begin(A), std::end(A) );
    ir::reverse( std::begin(A_E), std::end(A_E) );    
    ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
}

TEST(IntRange, ScalarBasic){
    ir::value_type A[]{ 1, 2, 3, 4, 5 };
    ir::value_type A_E[]{ 3, 6, 9, 12, 15};
    ir::scalar_multiplication( std::begin(A), std::end(A), 3 );
    ASSERT_EQ( std::distance( std::begin(A), std::end(A) ), std::distance( std::begin(A_E), std::end(A_E) ) );
}


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
