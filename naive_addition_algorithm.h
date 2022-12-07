#pragma once

#include "basic_algorithm.h"

class NaiveAdditionAlgorithm : public IBasicAlgorithm {

public:
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};