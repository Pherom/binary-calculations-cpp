#pragma once

#include "algorithm.h"
#include "long_addition_algorithm.h"

class DynamicProgrammingMultiplicationAlgorithm : public IAlgorithm {

private:
	IAlgorithm* addition_algorithm = new LongAdditionAlgorithm();

public:
	~DynamicProgrammingMultiplicationAlgorithm();
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
