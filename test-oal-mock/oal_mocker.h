#ifndef CMOCK_TEST_MATH_MOCKER_H_
#define CMOCK_TEST_MATH_MOCKER_H_

#include "cmock/cmock.h"

#include "oal-adapter.h"

class MathMocker : public CMockMocker<MathMocker>
{
public:
    MOCK_METHOD2(divide, int(int, int));
    MOCK_METHOD2(substract, int(int, int));
    MOCK_METHOD1(negate, int(int));
	MOCK_METHOD2(oal_init, int(int, fp));
	MOCK_METHOD0(adapter_enable, int());
};

#endif /* CMOCK_TEST_MATH_MOCKER_H_ */
