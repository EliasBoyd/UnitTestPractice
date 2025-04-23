/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, two_Letter)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aab"));
}

TEST(PasswordTest, unequal)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("abaab"));
}

TEST(PasswordTest, krazy)
{
	Password my_password;
	ASSERT_EQ(8, my_password.count_leading_characters("aaaaaaaababbaaaabbbbbbaab"));
}

TEST(PasswordTest, caseSensitive)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("aAaaAbaaA"));
}

TEST(PasswordTest, empty)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}