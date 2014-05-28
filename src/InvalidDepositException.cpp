/*
 * InvalidDepositException.cpp
 *
 *  Created on: 28 May 2014
 *      Author: andy
 */

#include "InvalidDepositException.h"

InvalidDepositException::InvalidDepositException(const std::string& message)
	_GLIBCXX_USE_NOEXCEPT :
	message_(message) {
}

const char * InvalidDepositException::what() const _GLIBCXX_USE_NOEXCEPT {
	return message_.c_str();
}
