#pragma once

#include "single_result_algorithm.h"
#include "long_addition_with_carry_algorithm.h"

class TwosComplementSubtractionAlgorithm : public ISingleResultAlgorithm {

private:
	IResultPairAlgorithm* addition_with_carry_algorithm = new LongAdditionWithCarryAlgorithm(true);

public:
	~TwosComplementSubtractionAlgorithm() { delete addition_with_carry_algorithm; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};