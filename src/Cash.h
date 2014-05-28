
#ifndef CASH_H_
#define CASH_H_

#include <exception>
#include <string>

class InvalidCashAmountException: public std::exception {
public:
	InvalidCashAmountException(const std::string& message) _GLIBCXX_USE_NOEXCEPT;
	virtual ~InvalidCashAmountException() _GLIBCXX_USE_NOEXCEPT {}
	virtual const char* what() const _GLIBCXX_USE_NOEXCEPT;
private:
	std::string message_;
};

class Cash {
public:
	Cash(float amount = 0.0f);
	virtual ~Cash();
	Cash& operator+(const Cash& amount);
	Cash& operator+=(const Cash& amount);
	Cash& operator-(const Cash& amount);
	Cash& operator-=(const Cash& amount);
	bool operator==(const Cash& amount) const;
	bool operator!=(const Cash& amount) const;
	bool operator <(const Cash& amount) const;
	bool operator <=(const Cash& amount) const;
	bool operator >(const Cash& amount) const;
	bool operator >=(const Cash& amount) const;
private:
	float amount_;
};

#endif /* CASH_H_ */
