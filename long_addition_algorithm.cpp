#include "long_addition_algorithm.h"
#include <deque>

BinaryNumber LongAdditionAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2) {
	deque<bool> result_binary_array;
	size_t index1 = 0, index2 = 0, logSize1 = binary_number1.logicalSize(), logSize2 = binary_number2.logicalSize();
	bool resBit, carry = false;

	while (index1 < logSize1 && index2 < logSize2) {
		resBit = (binary_number1[index1] != binary_number2[index2]) != carry;
		carry = (binary_number1[index1] && binary_number2[index2])
			|| ((binary_number1[index1] != binary_number2[index2]) && carry);
		result_binary_array.push_back(resBit);
		index1++;
		index2++;
	}

	while (index1 < logSize1) {
		resBit = binary_number1[index1] != carry;
		carry = binary_number1[index1] && carry;
		result_binary_array.push_back(resBit);
		index1++;
	}

	while (index2 < logSize2) {
		resBit = binary_number2[index2] != carry;
		carry = binary_number2[index2] && carry;
		result_binary_array.push_back(resBit);
		index2++;
	}

	if (carry) {
		result_binary_array.push_back(carry);
	}

	return BinaryNumber(result_binary_array);
}