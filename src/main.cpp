#include <gtest/gtest.h>

#include "Cash.h"
#include "Account.h"
#include "InvalidWithdrawException.h"
#include "InvalidDepositException.h"

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

TEST(AccountTestCase,AWidthdrawOf200OnAccountOf1000Result800){
	Cash amount(1000);
	Cash widthdraw(200);
	Account account(amount);
	ASSERT_EQ(account.withdraw(widthdraw),Cash(800));
}

TEST(AccountTestCase,AWidthdrawOf1200OnAccountOf1000ResultsNegative200){
	Cash amount(1000);
	Cash widthdraw(1200);
	Account account(amount);
	ASSERT_EQ(account.withdraw(widthdraw),Cash(0) - Cash(200));
}

TEST(AccountTestCase,CannotWidthdrawFromNegativeBalance){
	Cash amount(1000);
	Cash widthdraw(1200);
	Account account(amount);
	ASSERT_EQ(account.withdraw(widthdraw),Cash(0) - Cash(200));
	ASSERT_THROW(account.withdraw(Cash(100)), InvalidWithdrawException);
}

TEST(AccountTestCase,Deposit1200on1000ResultsIn2200){
	Cash amount(1000);
	Cash deposit(1200);
	Account account(amount);
	ASSERT_EQ(account.deposit(deposit),Cash(2200));
}

TEST(AccountTestCase,DepositZeroResultsInSameAmount){
	Cash amount(1000);
	Cash deposit(0);
	Account account(amount);
	ASSERT_EQ(account.deposit(deposit),amount);
}

TEST(AccountTestCase,CannotDepositANegativeAmount){
	Cash amount(1000);
	Cash deposit = Cash(0) - Cash(200);
	Account account(amount);
	ASSERT_THROW(account.deposit(deposit),InvalidDepositException);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

