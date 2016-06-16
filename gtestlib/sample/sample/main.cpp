#include <stdio.h>

#include "gtest/gtest.h"


int myadd(int a, int b)
{
	return a + b;
}

TEST(Test_myadd, IsReturnAdd)
{
	EXPECT_EQ(2, myadd(4, 10));
	EXPECT_EQ(14, myadd(4, 10));
}


class SuiRuiEnvironment : public testing::Environment
{

public:
	virtual void SetUp()
	{
		std::cout << "SuiRui Environment SetUP" << std::endl;
	}
	virtual void TearDown()
	{
		std::cout << "SuiRui Environment TearDown" << std::endl;
	}
};

class SuiRuiSuiteEventTest : public testing::Test 
{
public:
	static void SetUpTestCase() {
		std::cout << "SuiRui SuiRuiSuiteEventTest SetUpTestCase" << std::endl;
	}
	static void TearDownTestCase() {
		std::cout << "SuiRui SuiRuiSuiteEventTest TearDownTestCase" << std::endl;
	}
	// Some expensive resource shared by all tests.
	//static T* shared_resource_;
};

//测试套事件
TEST_F(SuiRuiSuiteEventTest, TestSuiteName1)
{
	//这里添加测试套用例TestCaseName1

	return;
}


class CaseEventTest : public testing::Test
{
public:
	static void SetUp() {
		std::cout << "SuiRui CaseEventTest SetUp" << std::endl;
	}
	static void TearDown() {
		std::cout << "SuiRui CaseEventTest TearDown" << std::endl;
	}
	// Some expensive resource shared by all tests.
	//static T* shared_resource_;
};

int main(int argc, char **argv) 
{
	testing::AddGlobalTestEnvironment(new SuiRuiEnvironment);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
