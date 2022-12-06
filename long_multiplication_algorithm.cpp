#include "long_multiplication_algorithm.h"
#include "long_addition_algorithm.h"

BinaryNumber LongMultiplicationAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	size_t logSize1 = binary_number1.logicalSize();
	BinaryNumber result = BinaryNumber(0), binary_number2_copy = binary_number2;
	IAlgorithm* addition_algorithm = new LongAdditionAlgorithm();

	for (size_t i = logSize1; i-- > 0; ) {
		if (binary_number1[i]) {
			result = addition_algorithm->calculate(result, binary_number2_copy.shiftLeft(i));
			binary_number2_copy.shiftRight(i);
		}
	}

	delete addition_algorithm;

	return result;
}