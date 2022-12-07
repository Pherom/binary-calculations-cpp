#include "long_addition_with_carry_algorithm.h"
#include <deque>
//101
//001
BinaryNumber LongAdditionWithCarryAlgorithm::calculate(const BinaryNumber& binary_number1, const BinaryNumber& binary_number2, BinaryNumber& carry) {
	deque<bool> result_binary_array;
	size_t index1 = 0, index2 = 0, log_size1 = binary_number1.logicalSize(), log_size2 = binary_number2.logicalSize();
	bool resBit, carry_as_bool = false;

	while (index1 < log_size1 && index2 < log_size2) {
		resBit = (binary_number1[index1] != binary_number2[index2]) != carry_as_bool;
		carry_as_bool = (binary_number1[index1] && binary_number2[index2])
			|| ((binary_number1[index1] != binary_number2[index2]) && carry_as_bool);
		result_binary_array.push_back(resBit);
		index1++;
		index2++;
	}

	while (index1 < log_size1) {
		resBit = binary_number1[index1] != carry_as_bool;
		carry_as_bool = binary_number1[index1] && carry_as_bool;
		result_binary_array.push_back(resBit);
		index1++;
	}

	while (index2 < log_size2) {
		resBit = binary_number2[index2] != carry_as_bool;
		carry_as_bool = binary_number2[index2] && carry_as_bool;
		result_binary_array.push_back(resBit);
		index2++;
	}

	if (carry_as_bool && !discard_carry) {
		result_binary_array.push_back(carry_as_bool);
	}

	carry = BinaryNumber(carry_as_bool);
	return BinaryNumber(result_binary_array);
}