/*
 * Cash.cpp
 *
 *  Created on: 23 May 2014
 *      Author: andy
 */

#include "Cash.h"

using std::exception;

InvalidCashAmountException::InvalidCashAmountException(const std::string& message) _GLIBCXX_USE_NOEXCEPT:
	message_(message){
}

const char* InvalidCashAmountException::what() const _GLIBCXX_USE_NOEXCEPT{
	return message_.c_str();
}

Cash::Cash(float amount) :
	amount_(amount) {
	if(amount_ < 0.0f){
		throw InvalidCashAmountException("Invalid cash amount!");
	}
}

Cash::~Cash() {
}

Cash& Cash::operator+(const Cash& amount) {
	amount_ = amount_ + amount.amount_;
	return *this;
}

Cash& Cash::operator-(const Cash& amount) {
	amount_ = amount_ - amount.amount_;
	return *this;
}

bool Cash::operator==(const Cash& amount) const{
	return amount_ == amount.amount_;
}

bool Cash::operator!=(const Cash& amount) const{
	return !(*this == amount);
}

Cash& Cash::operator+=(const Cash& amount){
	return this->operator +(amount);
}

Cash& Cash::operator-=(const Cash& amount){
	return this->operator -(amount);
}

bool Cash::operator<(const Cash& amount) const{
	return (amount_ < amount.amount_);
}

bool Cash::operator>(const Cash& amount) const{
	return (amount_ > amount.amount_);
}

bool Cash::operator<=(const Cash& amount) const{
	return ((*this < amount) || (*this == amount));
}

bool Cash::operator>=(const Cash& amount) const{
	return ((*this > amount) || (*this == amount));
}

