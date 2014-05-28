
#include "Account.h"

#include "InvalidWithdrawException.h"
#include "InvalidDepositException.h"

Account::Account(const Cash& initialAmount) :
	amount_(initialAmount) {
}

Account::~Account() {
}

const Cash& Account::withdraw(const Cash& amount) {
	if(amount < 0){
		throw InvalidWithdrawException("Impossible to withdraw a negative amount.");
	}
	if (amount_ < 0){
		throw InvalidWithdrawException("Impossible to withdraw from a negative balance.");
	}
	amount_ = amount_ - amount;
	return amount_;
}

const Cash& Account::deposit(const Cash& amount) {
	if(amount < 0){
		throw InvalidDepositException("Impossible to widtdraw a negative amount.");
	}
	amount_ = amount_ + amount;
	return amount_;
}
