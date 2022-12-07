#pragma once

#include "basic_algorithm.h"
#include "long_addition_with_carry_algorithm.h"

class LongAdditionAlgorithm : public IBasicAlgorithm {

private:
	IResultPairAlgorithm* long_addition_with_carry_algorithm = new LongAdditionWithCarryAlgorithm();

public:
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
