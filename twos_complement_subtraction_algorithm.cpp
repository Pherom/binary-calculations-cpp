#include "twos_complement_subtraction_algorithm.h"

BinaryNumber TwosComplementSubtractionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	BinaryNumber binary_number1_copy = binary_number1, binary_number2_copy = binary_number2;
	bool carry;

	//Add sign bits
	binary_number1_copy.addTrailingZeros(1);
	binary_number2_copy.addTrailingZeros(1);

	binary_number2_copy.changeToOnesComplement();
	++binary_number2_copy;

	BinaryNumber result = addition_algorithm.calculateDiscardCarry(binary_number1_copy, binary_number2_copy, true, carry);

	if (!carry) {
		throw new exception("Negative numbers are not supported");
	}

	return result;
}