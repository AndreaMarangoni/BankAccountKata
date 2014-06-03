
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "Cash.h"

class Account {
public:
	Account(const Cash& initialAmount);
	virtual ~Account();
	void withdraw(const Cash& amount);
	void deposit(const Cash& amount);
	bool operator==(const Account& account) const;
	bool operator!=(const Account& account) const;
private:
	Cash amount_;
};

#endif /* ACCOUNT_H_ */
