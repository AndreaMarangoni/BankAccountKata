
#include "Account.h"

#include "InvalidWithdrawException.h"
#include "InvalidDepositException.h"

Account::Account(const Cash& initialAmount) :
	amount_(initialAmount) {
}

Account::~Account() {
}

void Account::withdraw(const Cash& amount) {
	if(amount < 0){
		throw InvalidWithdrawException("Impossible to withdraw a negative amount.");
	}
	if (amount_ < 0){
		throw InvalidWithdrawException("Impossible to withdraw from a negative balance.");
	}
	amount_ = amount_ - amount;
}

void Account::deposit(const Cash& amount) {
	if(amount < 0){
		throw InvalidDepositException("Impossible to widtdraw a negative amount.");
	}
	amount_ = amount_ + amount;
}

bool Account::operator==(const Account& account) const{
	return amount_ == account.amount_;
}

bool Account::operator!=(const Account& account) const{
	return (*this != account);
}
