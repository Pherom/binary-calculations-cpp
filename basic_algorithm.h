#pragma once

#include "binary_number.h"

class IBasicAlgorithm {

public:
	virtual ~IBasicAlgorithm() {};
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) = 0;

};
