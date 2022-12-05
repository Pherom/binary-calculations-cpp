#include "naive_addition_algorithm.h"

BinaryNumber NaiveAdditionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	BinaryNumber binary_number1_copy = binary_number1, binary_number2_copy = binary_number2;
	
	while (binary_number1_copy != 0) {
		--binary_number1_copy;
		++binary_number2_copy;
	}

	return binary_number2_copy;
}