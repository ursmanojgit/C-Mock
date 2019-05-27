#include "oal_mocker.h"

CMOCK_MOCK_FUNCTION2(MathMocker, divide, int(int, int));
CMOCK_MOCK_FUNCTION2(MathMocker, substract, int(int, int));
CMOCK_MOCK_FUNCTION1(MathMocker, negate, int(int));
CMOCK_MOCK_FUNCTION2(MathMocker, oal_init, int(int, fp));
CMOCK_MOCK_FUNCTION0(MathMocker, adapter_enable, int());

