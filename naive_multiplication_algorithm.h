#pragma once

#include "single_result_algorithm.h"
#include "long_addition_algorithm.h"

class NaiveMultiplicationAlgorithm : public ISingleResultAlgorithm {

private:
	ISingleResultAlgorithm* addition_algorithm = new LongAdditionAlgorithm();

public:
	~NaiveMultiplicationAlgorithm() { delete addition_algorithm; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};