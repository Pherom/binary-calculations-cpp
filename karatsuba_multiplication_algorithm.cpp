#include "karatsuba_multiplication_algorithm.h"

//10101
//1011

//010101
//001011

//010 101
//001 011

//111
//100

//10
//11100
//1111

//11100 - 10 - 1111 = 1011

//10000000
//1011000
//1111

//11100111


//011100 + 000110 = 100010 = (2) 011110
BinaryNumber KaratsubaMultiplicationAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	if (binary_number1.logicalSize() <= 4 && binary_number2.logicalSize() <= 4) {
		return termination_multiplication_algorithm->calculate(binary_number1, binary_number2);
	}

	BinaryNumber binary_number1_copy = binary_number1, binary_number2_copy = binary_number2;
	size_t matched_size = BinaryNumber::matchSizeEven(binary_number1_copy, binary_number2_copy);

	BinaryNumber binary_number1_first_half = binary_number1_copy.subBinaryNumber(0, matched_size / 2);
	BinaryNumber binary_number1_second_half = binary_number1_copy.subBinaryNumber(matched_size / 2, matched_size);

	BinaryNumber binary_number2_first_half = binary_number2_copy.subBinaryNumber(0, matched_size / 2);
	BinaryNumber binary_number2_second_half = binary_number2_copy.subBinaryNumber(matched_size / 2, matched_size);

	BinaryNumber sum_1fh_1sh = addition_algorithm->calculate(binary_number1_first_half, binary_number1_second_half);
	BinaryNumber sum_2fh_2sh = addition_algorithm->calculate(binary_number2_first_half, binary_number2_second_half);

	BinaryNumber mult_1fh_2fh = calculate(binary_number1_first_half, binary_number2_first_half);
	BinaryNumber sum_1fh_1sh_times_sum_2fh_2sh = calculate(sum_1fh_1sh, sum_2fh_2sh);
	BinaryNumber mult_1sh_2sh = calculate(binary_number1_second_half, binary_number2_second_half);

	BinaryNumber diff = subtraction_algorithm->calculate(subtraction_algorithm->calculate(sum_1fh_1sh_times_sum_2fh_2sh, mult_1fh_2fh), mult_1sh_2sh);

	BinaryNumber& addend1 = mult_1fh_2fh.shiftLeft(matched_size);
	BinaryNumber& addend2 = diff.shiftLeft(matched_size / 2);
	BinaryNumber& addend3 = mult_1sh_2sh;

	BinaryNumber result = addition_algorithm->calculate(addend1, addend2);
	result = addition_algorithm->calculate(result, addend3);
	
	return result;
}