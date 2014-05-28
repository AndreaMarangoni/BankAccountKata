#ifndef INVALIDWITDRAWEXCEPTION_H_
#define INVALIDWITDRAWEXCEPTION_H_

#include <exception>
#include <string>

class InvalidWithdrawException: public std::exception {
public:
	explicit InvalidWithdrawException(const std::string& message) _GLIBCXX_USE_NOEXCEPT;
	virtual ~InvalidWithdrawException() _GLIBCXX_USE_NOEXCEPT{}
	virtual const char * what() const _GLIBCXX_USE_NOEXCEPT;
private:
	std::string message_;
};

#endif /* INVALIDWITDRAWEXCEPTION_H_ */
