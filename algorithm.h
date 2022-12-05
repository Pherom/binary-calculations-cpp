#pragma once

#include "binary_number.h"

class IAlgorithm {

public:
	virtual ~IAlgorithm() {};
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) = 0;

};
