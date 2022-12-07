#pragma once

#include "binary_number.h"

class ISingleResultAlgorithm {

public:
	virtual ~ISingleResultAlgorithm() {};
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) = 0;

};
