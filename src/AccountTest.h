/*
 * AccountTest.h
 *
 *  Created on: 3 Jun 2014
 *      Author: andy
 */

#ifndef ACCOUNTTEST_H_
#define ACCOUNTTEST_H_

#include <gtest/gtest.h>

#include "Account.h"
#include "InvalidDepositException.h"
#include "InvalidWithdrawException.h"

TEST(AccountTestCase,AWidthdrawOf200OnAccountOf1000Result800){
	Cash amount(1000);
	Cash widthdraw(200);
	Cash balance(800);

	Account account(amount);
	account.withdraw(widthdraw);

	ASSERT_EQ(account,Account(balance));
}

//DROPPED
//TEST(AccountTestCase,AWidthdrawOf1200OnAccountOf1000ResultsNegative200){
//	Cash amount(1000);
//	Cash widthdraw(1200);
//	Account account(amount);
//	account.withdraw(widthdraw);
//}

TEST(AccountTestCase,CannotWidthdrawFromNegativeBalance){
	Cash amount(1000);
	Cash widthdraw(1200);
	Account account(amount);
	account.withdraw(widthdraw);
	ASSERT_EQ(account,Account(Cash(0) - Cash(200)));
	ASSERT_THROW(account.withdraw(Cash(100)), InvalidWithdrawException);
}

TEST(AccountTestCase,Deposit1200on1000ResultsIn2200){
	Cash amount(1000);
	Cash deposit(1200);
	Cash balance(2200);
	Account account(amount);
	account.deposit(deposit);
	ASSERT_EQ(account,Account(balance));
}

TEST(AccountTestCase,DepositZeroResultsInSameAmount){
	Cash amount(1000);
	Cash deposit(0);
	Account account(amount);
	account.deposit(deposit);
	ASSERT_EQ(account,Account(amount));
}

TEST(AccountTestCase,CannotDepositANegativeAmount){
	Cash amount(1000);
	Cash deposit = Cash(0) - Cash(200);
	Account account(amount);
	ASSERT_THROW(account.deposit(deposit),InvalidDepositException);
}


#endif /* ACCOUNTTEST_H_ */
