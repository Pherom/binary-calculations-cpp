#include "naive_multiplication_algorithm.h"
#include "naive_addition_algorithm.h"

BinaryNumber NaiveMultiplicationAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	BinaryNumber counter = binary_number1;
	BinaryNumber result = binary_number2;
	ISingleResultAlgorithm* addition_algorithm = new NaiveAdditionAlgorithm();

	if (counter != 0) {
		--counter;
	}

	while (counter != 0) {
		result = addition_algorithm->calculate(result, binary_number2);
		--counter;
	}

	delete addition_algorithm;

	return result;
}