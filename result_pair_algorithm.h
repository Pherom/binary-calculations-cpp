#pragma once

#include "binary_number.h"

class IResultPairAlgorithm {

public:
	virtual ~IResultPairAlgorithm() {};
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& otherResult) = 0;

};