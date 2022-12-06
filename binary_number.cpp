#include "binary_number.h"

BinaryNumber::BinaryNumber(size_t number) {
	fromDecimalRec(number);
}

BinaryNumber::BinaryNumber(const string& binary_string) {
	size_t input_length = binary_string.length();
	char bit_as_char;
	for (size_t i = input_length; i-- > 0; ) {
		bit_as_char = binary_string[i];
		if (bit_as_char == '0' || bit_as_char == '1')
			binary_array.push_back(bit_as_char - '0');
		else throw new exception("Bit must be 0 or 1");
	}
}

BinaryNumber::BinaryNumber(const deque<bool>& binary_array) {
	this->binary_array = binary_array;
}

BinaryNumber::BinaryNumber(const BinaryNumber& binary_number) {
	for (bool bit_as_bool : binary_number) {
		binary_array.push_back(bit_as_bool);
	}
}

size_t BinaryNumber::countTrailingZeros() const {
	size_t count = 0;
	size_t index = size() - 1;
	while (index > 0 && (*this)[index] == 0) {
		count++;
		index--;
	}

	return count;
}

void BinaryNumber::fromDecimalRec(size_t number) {
	if (number / 2 != 0) {
		fromDecimalRec(number / 2);
	}
	binary_array.push_front(number % 2);
}

bool BinaryNumber::operator[](size_t index) const {
	return binary_array[index];
}

bool BinaryNumber::operator==(const BinaryNumber& binary_number) const {
	bool equal = true;

	size_t index1 = 0, index2 = 0;
	size_t logSize1 = logicalSize(), logSize2 = binary_number.logicalSize();

	if (logSize1 != logSize2)
		equal = false;

	for (; equal && index1 < logSize1 && index2 < logSize2; index1++, index2++) {
		if ((*this)[index1] != binary_number[index2])
			equal = false;
	}

	return equal;
}

bool BinaryNumber::operator!=(const BinaryNumber& binary_number) const {
	return !(*this == binary_number);
}

bool BinaryNumber::operator==(size_t number) const {
	BinaryNumber binary_number = BinaryNumber(number);
	return *this == binary_number;
}

bool BinaryNumber::operator!=(size_t number) const {
	return !(*this == number);
}

size_t BinaryNumber::size() const {
	return binary_array.size();
}

size_t BinaryNumber::logicalSize() const {
	return size() - countTrailingZeros();
}

void BinaryNumber::changeByOne(CHANGE_BY_ONE_OPERATION operation) {
	bool carry = true;
	for (size_t i = 0; i < size(); i++) {
		if (binary_array[i] == true && operation == BinaryNumber::INCREMENT) {
			binary_array[i] = false;
		}
		else if (binary_array[i] == false && operation == BinaryNumber::DECREMENT) {
			binary_array[i] = true;
		}
		else {
			binary_array[i] = operation == BinaryNumber::INCREMENT;
			carry = false;
			break;
		}
	}
	if (carry) {
		if (operation == BinaryNumber::INCREMENT) {
			binary_array.push_back(true);
		}
		else {
			throw new exception("Negative numbers are not supported");
		}
	}
}

BinaryNumber& BinaryNumber::operator++() {
	changeByOne(BinaryNumber::INCREMENT);
	return *this;
}

BinaryNumber& BinaryNumber::operator--() {
	changeByOne(BinaryNumber::DECREMENT);
	return *this;
}

BinaryNumber BinaryNumber::operator++(int) {
	BinaryNumber old = *this;
	operator++();
	return old;
}

BinaryNumber BinaryNumber::operator--(int) {
	BinaryNumber old = *this;
	operator--();
	return old;
}

ostream& operator<<(ostream& os, const BinaryNumber& binary_number)
{
	size_t logSize = binary_number.logicalSize();
	bool bit_as_bool;
	for (size_t i = logSize; i-- > 0; ) {
		bit_as_bool = binary_number[i];
		os << bit_as_bool ? '1' : '0';
	}
	return os;
}

void BinaryNumber::shift(SHIFT_DIRECTION direction, size_t amount) {
	switch (direction) {
	case LEFT:
		for (int i = 0; i < amount; i++) {
			binary_array.push_front(false);
		}
		break;
	case RIGHT:
		for (int i = 0; i < amount; i++) {
			binary_array.pop_front();
		}
		break;
	}
}

BinaryNumber& BinaryNumber::shiftLeft(size_t amount) {
	shift(LEFT, amount);
	return *this;
}

BinaryNumber& BinaryNumber::shiftRight(size_t amount) {
	shift(RIGHT, amount);
	return *this;
}