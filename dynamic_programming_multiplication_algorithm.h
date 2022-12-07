#pragma once

#include "basic_algorithm.h"
#include "long_addition_algorithm.h"

class DynamicProgrammingMultiplicationAlgorithm : public IBasicAlgorithm {

private:
	IBasicAlgorithm* addition_algorithm = new LongAdditionAlgorithm();

public:
	~DynamicProgrammingMultiplicationAlgorithm();
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
