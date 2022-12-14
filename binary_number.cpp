#include "binary_number.h"
#include <regex>

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
	size_t log_size1 = logicalSize(), log_size2 = binary_number.logicalSize();

	if (log_size1 != log_size2)
		equal = false;

	for (; equal && index1 < log_size1 && index2 < log_size2; index1++, index2++) {
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

bool BinaryNumber::operator<(const BinaryNumber& binary_number) const {
	bool result = false;
	size_t log_size1 = logicalSize(), log_size2 = binary_number.logicalSize();

	if (log_size1 > log_size2) {
		result = false;
	}

	else if (log_size1 < log_size2) {
		result = true;
	}

	else {
		for (size_t i = log_size1; i-- > 0; ) {
			if (binary_array[i] && !binary_number[i]) {
				result = false;
				break;
			}
			else if (!binary_array[i] && binary_number[i]) {
				result = true;
				break;
			}
		}
	}

	return result;
}

bool BinaryNumber::operator<(size_t number) const {
	BinaryNumber binary_number = BinaryNumber(number);
	return *this < binary_number;
}

bool BinaryNumber::operator>(const BinaryNumber& binary_number) const {
	return binary_number < *this;
}

bool BinaryNumber::operator>(size_t number) const {
	BinaryNumber binary_number = BinaryNumber(number);
	return *this > binary_number;
}

bool BinaryNumber::operator<=(const BinaryNumber& binary_number) const {
	return !(*this > binary_number);
}

bool BinaryNumber::operator<=(size_t number) const {
	BinaryNumber binary_number = BinaryNumber(number);
	return *this <= binary_number;
}

bool BinaryNumber::operator>=(const BinaryNumber& binary_number) const {
	return !(*this < binary_number);
}

bool BinaryNumber::operator>=(size_t number) const {
	BinaryNumber binary_number = BinaryNumber(number);
	return *this >= binary_number;
}

size_t BinaryNumber::size() const {
	return binary_array.size();
}

size_t BinaryNumber::logicalSize() const {
	return size() - countTrailingZeros();
}

void BinaryNumber::changeByOne(BinaryNumber::CHANGE_BY_ONE_OPERATION operation, bool discard_carry) {
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
			if (!discard_carry) {
				binary_array.push_back(true);
			}
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

BinaryNumber& BinaryNumber::incrementDiscardCarry() {
	changeByOne(BinaryNumber::INCREMENT, true);
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

BinaryNumber BinaryNumber::subBinaryNumber(size_t start_index_included, size_t end_index_excluded) {
	size_t reverse_end_index_excluded = size() - start_index_included, reverse_start_index_included = size() - end_index_excluded;
	deque<bool> binary_array;
	for (size_t i = reverse_start_index_included; i < reverse_end_index_excluded; i++) {
		binary_array.push_back((this->binary_array)[i]);
	}

	return BinaryNumber(binary_array);
}

BinaryNumber BinaryNumber::getOnesComplement() {
	deque<bool> complement_binary_array;
	for (bool bit_as_bool : binary_array) {
		complement_binary_array.push_back(!bit_as_bool);
	}

	return BinaryNumber(complement_binary_array);
}

ostream& operator<<(ostream& os, const BinaryNumber& binary_number)
{
	size_t log_size = binary_number.logicalSize();
	bool bit_as_bool;
	for (size_t i = log_size; i-- > 0; ) {
		bit_as_bool = binary_number[i];
		os << bit_as_bool ? '1' : '0';
	}
	return os;
}

void BinaryNumber::shift(BinaryNumber::SHIFT_DIRECTION direction, size_t amount) {
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

BinaryNumber& BinaryNumber::addTrailingZeros(size_t amount) {
	for (int i = 0; i < amount; i++) {
		binary_array.push_back(false);
	}

	return *this;
}

BinaryNumber& BinaryNumber::addTrailingOnes(size_t amount) {
	for (int i = 0; i < amount; i++) {
		binary_array.push_back(true);
	}

	return *this;
}

BinaryNumber& BinaryNumber::changeToOnesComplement() {
	for (bool& bit_as_bool : binary_array) {
		bit_as_bool = !bit_as_bool;
	}

	return *this;
}

size_t BinaryNumber::matchSize(BinaryNumber& binary_number1, BinaryNumber& binary_number2) {
	size_t size1 = binary_number1.size(), size2 = binary_number2.size(), max = size1;

	if (size1 > size2) {
		binary_number2.addTrailingZeros(size1 - size2);
	}
	else if (size2 > size1) {
		binary_number1.addTrailingZeros(size2 - size1);
		max = size2;
	}

	return max;
}

size_t BinaryNumber::matchSizeEven(BinaryNumber& binary_number1, BinaryNumber& binary_number2) {
	size_t matched_size = matchSize(binary_number1, binary_number2);

	if (matched_size % 2 != 0) {
		binary_number1.addTrailingZeros(1);
		binary_number2.addTrailingZeros(1);
		++matched_size;
	}

	return matched_size;
}

bool BinaryNumber::isStringValidBinaryNumber(string binary_number_str) {
	const basic_regex<char> binary_regex("(1[01]*)|0");
	return regex_match(binary_number_str, binary_regex);
}

BinaryNumber BinaryNumber::generateByLength(size_t length) {
	bool rand_bit_as_bool = rand() & 1;
	deque<bool> binary_array;

	if (length == 1) {
		binary_array.push_back(rand_bit_as_bool);
		return BinaryNumber(binary_array);
	}

	for (int i = 0; i < length - 1; i++) {
		binary_array.push_back(rand_bit_as_bool);
		rand_bit_as_bool = rand() & 1;
	}

	binary_array.push_back(true);

	return BinaryNumber(binary_array);
}