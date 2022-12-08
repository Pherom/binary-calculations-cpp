#pragma once

#include "result_pair_algorithm.h"
#include "karatsuba_multiplication_algorithm.h"
#include "twos_complement_subtraction_algorithm.h"

class NaiveEuclideanDivisionAlgorithm : public IResultPairAlgorithm {

private:
	ISingleResultAlgorithm* multiplication_algorithm = new KaratsubaMultiplicationAlgorithm();
	ISingleResultAlgorithm* subtraction_algorithm = new TwosComplementSubtractionAlgorithm();

public:
	~NaiveEuclideanDivisionAlgorithm() { delete multiplication_algorithm, subtraction_algorithm; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& remainder);

};