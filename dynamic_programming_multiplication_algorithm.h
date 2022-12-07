#pragma once

#include "single_result_algorithm.h"
#include "long_addition_algorithm.h"

class DynamicProgrammingMultiplicationAlgorithm : public ISingleResultAlgorithm {

private:
	ISingleResultAlgorithm* addition_algorithm = new LongAdditionAlgorithm();

public:
	~DynamicProgrammingMultiplicationAlgorithm() { delete addition_algorithm; };
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
