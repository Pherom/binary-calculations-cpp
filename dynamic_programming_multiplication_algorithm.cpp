#include "dynamic_programming_multiplication_algorithm.h"

BinaryNumber DynamicProgrammingMultiplicationAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	if (binary_number1.logicalSize() <= 128 && binary_number2.logicalSize() <= 128) {
		return termination_multiplication_algorithm->calculate(binary_number1, binary_number2);
	}

	BinaryNumber binary_number1_copy = binary_number1, binary_number2_copy = binary_number2;
	size_t matched_size = BinaryNumber::matchSizeEven(binary_number1_copy, binary_number2_copy);

	BinaryNumber binary_number1_first_half = binary_number1_copy.subBinaryNumber(0, matched_size / 2);
	BinaryNumber binary_number1_second_half = binary_number1_copy.subBinaryNumber(matched_size / 2, matched_size);

	BinaryNumber binary_number2_first_half = binary_number2_copy.subBinaryNumber(0, matched_size / 2);
	BinaryNumber binary_number2_second_half = binary_number2_copy.subBinaryNumber(matched_size / 2, matched_size);

	BinaryNumber mult_1fh_2fh = calculate(binary_number1_first_half, binary_number2_first_half);
	BinaryNumber mult_1fh_2sh = calculate(binary_number1_first_half, binary_number2_second_half);
	BinaryNumber mult_1sh_2fh = calculate(binary_number1_second_half, binary_number2_first_half);
	BinaryNumber mult_1sh_2sh = calculate(binary_number1_second_half, binary_number2_second_half);

	BinaryNumber mult_1fh_2sh_add_mult_1sh_2fh = addition_algorithm->calculate(mult_1fh_2sh, mult_1sh_2fh);
	
	BinaryNumber& addend1 = mult_1fh_2fh.shiftLeft(matched_size);
	BinaryNumber& addend2 = mult_1fh_2sh_add_mult_1sh_2fh.shiftLeft(matched_size / 2);
	BinaryNumber& addend3 = mult_1sh_2sh;

	BinaryNumber result = addition_algorithm->calculate(addend1, addend2);
	result = addition_algorithm->calculate(result, addend3);
	return result;
}