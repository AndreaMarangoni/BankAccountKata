
#ifndef INVALIDDEPOSITEXCEPTION_H_
#define INVALIDDEPOSITEXCEPTION_H_

#include <exception>
#include <string>


class InvalidDepositException: public std::exception {
public:
	explicit InvalidDepositException(const std::string& message) _GLIBCXX_USE_NOEXCEPT;
	virtual ~InvalidDepositException() _GLIBCXX_USE_NOEXCEPT{}
	virtual const char * what() const _GLIBCXX_USE_NOEXCEPT;
private:
	std::string message_;
};

#endif /* INVALIDDEPOSITEXCEPTION_H_ */
