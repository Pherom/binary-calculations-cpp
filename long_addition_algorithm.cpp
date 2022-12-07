#include "long_addition_algorithm.h"
#include <deque>

BinaryNumber LongAdditionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	BinaryNumber carry = BinaryNumber(false);
	return long_addition_with_carry_algorithm->calculate(binary_number1, binary_number2, carry);
}