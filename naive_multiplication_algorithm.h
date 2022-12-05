#pragma once

#include "algorithm.h"

class NaiveMultiplicationAlgorithm : public IAlgorithm {

public:
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};