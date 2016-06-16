
#include <gtest/gtest.h>




int Foo(int a, int b)
{
	if (a == 0 || b == 0)
	{
		throw "don't do that";
	}
	int c = a % b;
	if (c == 0)
		return b;
	return Foo(b, c);
}

int Add(int a, int b)
{
	return a + b;
}



TEST(AddTest, HH)
{
	EXPECT_EQ(3, Add(1, 2));
	//	ASSERT_EQ(6, Add(3, 4));
	ASSERT_EQ(5, Add(3, 4));
	ASSERT_EQ(7, Add(3, 4));
	//	EXPECT_EQ(6, Add(3, 4));
	//	EXPECT_EQ(5, Add(3, 4));
	//	EXPECT_EQ(7, Add(3, 4));
}

TEST(FooTest, HandleNoneZeroInput)
{
	EXPECT_EQ(2, Foo(4, 10));
	EXPECT_EQ(6, Foo(30, 18));
}