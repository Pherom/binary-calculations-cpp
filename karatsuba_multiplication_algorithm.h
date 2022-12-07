#pragma once

#include "algorithm.h"
#include "twos_complement_subtraction_algorithm.h"

class KaratsubaMultiplicationAlgorithm : public IAlgorithm {

private:
	IAlgorithm* addition_algorithm = new LongAdditionAlgorithm();
	IAlgorithm* subtraction_algorithm = new TwosComplementSubtractionAlgorithm();

public:
	~KaratsubaMultiplicationAlgorithm();
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2);

};
