#include "binary_number.h"

BinaryNumber::BinaryNumber(size_t number) {
	fromDecimalRec(number);
}

BinaryNumber::BinaryNumber(initializer_list<unsigned char> binary_array_values) {
	for (char bit : binary_array_values) {
		if (bit == 0 || bit == 1)
			binary_array.push_back(bit);
		else throw new exception("Bit must be 0 or 1");
	}
}

BinaryNumber::BinaryNumber(const string& binary_string) {
	for (char bit_as_char : binary_string) {
		if (bit_as_char == '0' || bit_as_char == '1')
			binary_array.push_back(bit_as_char - '0');
		else throw new exception("Bit must be 0 or 1");
	}
}

size_t BinaryNumber::countTrailingZeros() const {
	size_t count = 0;
	while ((*this)[count] == 0 && count < size() - 1) {
		count++;
	}

	return count;
}

void BinaryNumber::fromDecimalRec(size_t number) {
	if (number / 2 != 0) {
		fromDecimalRec(number / 2);
	}
	binary_array.push_back(number % 2);
}

bool BinaryNumber::operator[](size_t index) const {
	return binary_array[index];
}

bool BinaryNumber::operator==(const BinaryNumber& binary_number) {
	bool equal = true;

	size_t index1 = this->countTrailingZeros(), index2 = binary_number.countTrailingZeros();

	if (this->size() - index1 != binary_number.size() - index2)
		equal = false;

	for (; index1 < this->size() && index2 < binary_number.size() && equal; index1++, index2++) {
		if ((*this)[index1] != binary_number[index2])
			equal = false;
	}

	return equal;
}

size_t BinaryNumber::size() const {
	return binary_array.size();
}

size_t BinaryNumber::logicalSize() const {
	return size() - countTrailingZeros();
}

ostream& operator<<(ostream& os, const BinaryNumber& binary_number)
{
	for (bool bit_as_bool : binary_number) {
		os << bit_as_bool ? '1' : '0';
	}
	return os;
}