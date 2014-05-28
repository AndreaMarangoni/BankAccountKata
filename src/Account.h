/*
 * Account.h
 *
 *  Created on: 23 May 2014
 *      Author: andy
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "Cash.h"

class Account {
public:
	Account(const Cash& initialAmount);
	virtual ~Account();
	const Cash& withdraw(const Cash& amount);
	const Cash& deposit(const Cash& amount);
private:
	Cash amount_;
};

#endif /* ACCOUNT_H_ */
