#include "SimpleUt.hpp"

TEST(DummyPass)
{
	std::cout << "Dummy" << std::endl;
}
TEST(Fail)
{
	IS_EQ(1, 2);
	IS_NOT_EQ(1, 1);
	IS_TRUE(1==2);
	int a=1, b=2;
	IS_FALSE(a != b);
}
TEST(Pass)
{
	IS_EQ(1, 1);
	IS_NOT_EQ(1, 2);
	IS_TRUE(1 == 1);
	int a=1, b=2;
	IS_FALSE(a==b);
}
TEST(FailExceptionInTest)
{
	std::cout << "DummyFException" << std::endl;
	throw std::runtime_error("Dummy");
}
TEST(PassException)
{
	std::cout << "pass1" << std::endl;
	THROWS(throw std::exception());
	std::cout << "pass2" << std::endl;
}

void dum() {}

TEST(FailException)
{
	std::cout << "fail1" << std::endl;
	THROWS(dum());
	std::cout << "fail2" << std::endl;
}

int main()
{
	MAIN_START;

	RUN_TEST(DummyPass);
	RUN_TEST(FailException);
	RUN_TEST(PassException);
	RUN_TEST(FailExceptionInTest);
	RUN_TEST(Fail);
	RUN_TEST(Pass);

	MAIN_END;
	return 0;
}
