#include <iostream>
#include <vector>

#include <gtest/gtest.h>

//#include "vector.hpp"

TEST(TestCase, Logic)
{
    std::string s{"abcd"};
    ASSERT_EQ(s.size(), 4);
}

class TestFoo : public ::testing::Test
{
protected:
    void SetUp()
    {
        array = {1,2,3,4,5,6,7};
    }
    void TearDown()
    {
    }

    std::vector<int> array;
};

TEST_F(TestFoo, test_const_method)
{
    ASSERT_EQ(array.size(), 7);
    array.push_back(8);
    ASSERT_EQ(array.size(), 8);
}

TEST_F(TestFoo, test_string_method)
{
    ASSERT_EQ(array.size(), 7);
    ASSERT_EQ(array.capacity(), 7);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


