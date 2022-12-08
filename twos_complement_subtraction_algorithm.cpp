#include "twos_complement_subtraction_algorithm.h"

BinaryNumber TwosComplementSubtractionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	BinaryNumber binary_number1_copy = binary_number1, binary_number2_copy = binary_number2;
	BinaryNumber::matchSize(binary_number1_copy, binary_number2_copy);
	BinaryNumber carry = BinaryNumber(false);

	//Add sign bits
	binary_number1_copy.addTrailingZeros(1);
	binary_number2_copy.addTrailingZeros(1);

	binary_number2_copy.changeToOnesComplement();
	binary_number2_copy.incrementDiscardCarry();

	BinaryNumber result = addition_with_carry_algorithm->calculate(binary_number1_copy, binary_number2_copy, carry);

	return result;
}