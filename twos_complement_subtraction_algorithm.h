#pragma once

#include "basic_algorithm.h"
#include "long_addition_with_carry_algorithm.h"

class TwosComplementSubtractionAlgorithm : public IBasicAlgorithm {

private:
	IResultPairAlgorithm* addition_with_carry_algorithm = new LongAdditionWithCarryAlgorithm(true);

public:
	~TwosComplementSubtractionAlgorithm();
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};