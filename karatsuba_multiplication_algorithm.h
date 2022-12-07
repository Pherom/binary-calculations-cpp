#pragma once

#include "basic_algorithm.h"
#include "long_addition_algorithm.h"
#include "twos_complement_subtraction_algorithm.h"

class KaratsubaMultiplicationAlgorithm : public IBasicAlgorithm {

private:
	IBasicAlgorithm* addition_algorithm = new LongAdditionAlgorithm();
	IBasicAlgorithm* subtraction_algorithm = new TwosComplementSubtractionAlgorithm();

public:
	~KaratsubaMultiplicationAlgorithm();
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
