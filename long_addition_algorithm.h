#pragma once

#include "single_result_algorithm.h"
#include "long_addition_with_carry_algorithm.h"

class LongAdditionAlgorithm : public ISingleResultAlgorithm {

private:
	IResultPairAlgorithm* long_addition_with_carry_algorithm = new LongAdditionWithCarryAlgorithm();

public:
	~LongAdditionAlgorithm() { delete long_addition_with_carry_algorithm; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
