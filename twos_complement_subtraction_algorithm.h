#pragma once

#include "algorithm.h"
#include "long_addition_algorithm.h"

class TwosComplementSubtractionAlgorithm : public IAlgorithm {

private:
	LongAdditionAlgorithm addition_algorithm;

public:
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};