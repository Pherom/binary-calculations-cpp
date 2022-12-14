#pragma once

#include "single_result_algorithm.h"
#include "long_addition_algorithm.h"
#include "twos_complement_subtraction_algorithm.h"
#include "long_multiplication_algorithm.h"

class KaratsubaMultiplicationAlgorithm : public ISingleResultAlgorithm {

private:
	ISingleResultAlgorithm* addition_algorithm = new LongAdditionAlgorithm();
	ISingleResultAlgorithm* subtraction_algorithm = new TwosComplementSubtractionAlgorithm();
	ISingleResultAlgorithm* termination_multiplication_algorithm = new LongMultiplicationAlgorithm();

public:
	~KaratsubaMultiplicationAlgorithm() { delete addition_algorithm, subtraction_algorithm, termination_multiplication_algorithm; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
