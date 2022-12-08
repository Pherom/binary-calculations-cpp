#pragma once

#include "single_result_algorithm.h"
#include "long_addition_algorithm.h"
#include "long_multiplication_algorithm.h"

class DynamicProgrammingMultiplicationAlgorithm : public ISingleResultAlgorithm {

private:
	ISingleResultAlgorithm* addition_algorithm = new LongAdditionAlgorithm();
	ISingleResultAlgorithm* termination_multiplication_algorithm = new LongMultiplicationAlgorithm();

public:
	~DynamicProgrammingMultiplicationAlgorithm() { delete addition_algorithm, termination_multiplication_algorithm; };
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
