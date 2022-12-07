#include "twos_complement_subtraction_algorithm.h"

BinaryNumber TwosComplementSubtractionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	BinaryNumber binary_number1_copy = binary_number1, binary_number2_copy = binary_number2;
	BinaryNumber carry = BinaryNumber(false);

	//Add sign bits
	binary_number1_copy.addTrailingZeros(1);
	binary_number2_copy.addTrailingZeros(1);

	binary_number2_copy.changeToOnesComplement();
	++binary_number2_copy;

	BinaryNumber result = addition_with_carry_algorithm->calculate(binary_number1_copy, binary_number2_copy, carry);

	if (!carry[0]) {
		throw new exception("Negative numbers are not supported");
	}

	return result;
}