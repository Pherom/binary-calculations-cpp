#pragma once

#include "binary_number.h"
#include "single_result_algorithm.h"
#include "result_pair_algorithm.h"
#include "long_addition_algorithm.h"
#include "twos_complement_subtraction_algorithm.h"
#include "karatsuba_multiplication_algorithm.h"

class BinarySearchEuclideanDivisionAlgorithm : public IResultPairAlgorithm {

private:
	ISingleResultAlgorithm* addition_algorithm = new LongAdditionAlgorithm();
	ISingleResultAlgorithm* subtraction_algorithm = new TwosComplementSubtractionAlgorithm();
	ISingleResultAlgorithm* multiplication_algorithm = new KaratsubaMultiplicationAlgorithm();

public:
	~BinarySearchEuclideanDivisionAlgorithm() { delete addition_algorithm, subtraction_algorithm, multiplication_algorithm; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& remainder);

};
