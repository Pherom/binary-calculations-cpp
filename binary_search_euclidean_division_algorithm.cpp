#include "binary_search_euclidean_division_algorithm.h"

BinaryNumber BinarySearchEuclideanDivisionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& remainder) {

	if (binary_number2 == 0) {
		throw new exception("Division by zero is undefined");
	}

	BinaryNumber quotient = BinaryNumber(0);
	BinaryNumber binary_number2_times_mid = BinaryNumber(0);

	BinaryNumber left = BinaryNumber(0);
	BinaryNumber right = binary_number1;
	BinaryNumber mid = BinaryNumber(0);

	while (left <= right) {
		mid = addition_algorithm->calculate(left, subtraction_algorithm->calculate(right, left).shiftRight(1));
		binary_number2_times_mid = multiplication_algorithm->calculate(binary_number2, mid);

		if (binary_number2_times_mid > binary_number1) {
			right = --mid;
		}

		else {
			remainder = subtraction_algorithm->calculate(binary_number1, binary_number2_times_mid);
			quotient = mid;
			left = ++mid;
		}
	}

	return quotient;

}