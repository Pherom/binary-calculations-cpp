#pragma once

#include "result_pair_algorithm.h"

class LongAdditionWithCarryAlgorithm : public IResultPairAlgorithm {

private:
	bool discard_carry;

public:
	LongAdditionWithCarryAlgorithm(bool discard_carry = false) { this->discard_carry = discard_carry; }
	virtual BinaryNumber calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& carry);

};
