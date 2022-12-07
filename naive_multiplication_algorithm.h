#pragma once

#include "single_result_algorithm.h"

class NaiveMultiplicationAlgorithm : public ISingleResultAlgorithm {

public:
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};