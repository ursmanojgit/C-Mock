#include <cmock/cmock.h>

#include "oal_mocker.h"
#include "iostream"

using namespace ::testing;
using ::testing::_;

using ::testing::InvokeArgument;

using namespace std;


int oal_cb(void) {
	cout<<"oal_cb: data="<<endl;
return 1;
	}

/**
 * Functions add and substract are mocked as long as MathMocker instance exists.
 * Once mock function is destroyed, call directs to real function.
 */
TEST(FunctionClassMockersTest, FunctionsAreMockedAsLongAsMockerInstanceExists) {

	{
		MathMocker mock;

		EXPECT_CALL(mock, adapter_enable()).WillOnce(Return(1));
		ASSERT_EQ(1, adapter_enable());

		//EXPECT_CALL(mock, oal_init(_).WillOnce(InvokeArgument<0>(5)).WillOnce(Return(1));
		EXPECT_CALL(mock, oal_init(_, _)).WillOnce(InvokeArgument<1>());
		//EXPECT_CALL(mock, oal_init(_)).WillOnce(Return(1)).WillOnce(InvokeArgument<0>());;
		//ASSERT_EQ(0, oal_init(1221, oal_cb));
		oal_init(1, oal_cb);
	}

	ASSERT_EQ(0, adapter_enable());
	//ASSERT_EQ(-1, substract(1, 2));
}
/*
TEST(FunctionClassMockersTest, ExceptionIfNotFound) {

	{
		MathMocker mock;

		EXPECT_CALL(mock, negate(3)).WillOnce(Return(-3));
		ASSERT_EQ(-3, negate(3));
	}

	EXPECT_THROW(negate(3), std::logic_error);
}*/

