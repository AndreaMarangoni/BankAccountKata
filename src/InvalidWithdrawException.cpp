#include "InvalidWithdrawException.h"

InvalidWithdrawException::InvalidWithdrawException(const std::string& message) _GLIBCXX_USE_NOEXCEPT :
	message_(message){
}

const char * InvalidWithdrawException::what() const _GLIBCXX_USE_NOEXCEPT{
	return message_.c_str();
}

