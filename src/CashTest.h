/*
 * CashTest.h
 *
 *  Created on: 3 Jun 2014
 *      Author: andy
 */

#ifndef CASHTEST_H_
#define CASHTEST_H_

#include <gtest/gtest.h>

#include "Cash.h"
#include "Account.h"

TEST(CashTestCase,AThousandPlusAHundredMakeAThousandHundred) {
	Cash cash(1000);
	Cash cash2(100);
	ASSERT_EQ(Cash(1100), cash+cash2);
}

TEST(CashTestCase,NegativeAmountThrowAnException) {
	ASSERT_THROW(Cash(-100), InvalidCashAmountException);
}

TEST(CashTestCase,AThousandMinusAHundredMakeANineHundred) {
	Cash cash(1000);
	Cash cash2(100);
	ASSERT_EQ(Cash(900), cash-cash2);
}

TEST(CashTestCase,AThousandMinusAThousandMakeZero) {
	Cash cash(1000);
	Cash cash2(1000);
	ASSERT_EQ(Cash(), cash-cash2);
}

TEST(AccountTestCase,ANegativeAccountThrowAnInvalidCashAmountException){
	ASSERT_THROW(Account(Cash(-100)), InvalidCashAmountException);
}


#endif /* CASHTEST_H_ */
