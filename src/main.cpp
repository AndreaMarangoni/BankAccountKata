#include <gtest/gtest.h>

#include "CashTest.h"
#include "AccountTest.h"

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

