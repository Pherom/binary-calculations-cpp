#include "naive_euclidean_division_algorithm.h"

BinaryNumber NaiveEuclideanDivisionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& remainder) {

	if (binary_number2 == 0) {
		throw new exception("Division by zero is undefined");
	}

	if (binary_number2 > binary_number1) {
		remainder = BinaryNumber(binary_number1);
		return BinaryNumber(0);
	}

	BinaryNumber quotient = BinaryNumber(0);
	do {
		++quotient;
		BinaryNumber binary_number2_times_quotient = multiplication_algorithm->calculate(binary_number2, quotient);
		remainder = subtraction_algorithm->calculate(binary_number1, binary_number2_times_quotient);
	} while (remainder >= binary_number2);

	return quotient;
}