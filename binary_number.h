#pragma once

#include <deque>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

class BinaryNumber {

private:
	deque<bool> binary_array;

	friend ostream& operator<<(ostream& os, const BinaryNumber& binary_number);

	size_t countTrailingZeros() const;
	void fromDecimalRec(size_t number);

	enum CHANGE_BY_ONE_OPERATION { INCREMENT, DECREMENT };
	enum SHIFT_DIRECTION { LEFT, RIGHT };

	void changeByOne(CHANGE_BY_ONE_OPERATION operation, bool discard_carry = false);
	void shift(SHIFT_DIRECTION direction, size_t amount);

public:
	BinaryNumber(size_t number);
	BinaryNumber(const string& binary_string);
	BinaryNumber(const deque<bool>& binary_array);
	BinaryNumber(const BinaryNumber& binary_number);

	bool operator[](size_t index) const;
	bool operator==(const BinaryNumber& binary_number) const;
	bool operator==(size_t number) const;
	bool operator!=(const BinaryNumber& binary_number) const;
	bool operator!=(size_t number) const;
	bool operator<(const BinaryNumber& binary_number) const;
	bool operator<(size_t number) const;
	bool operator>(const BinaryNumber& binary_number) const;
	bool operator>(size_t number) const;
	bool operator<=(const BinaryNumber& binary_number) const;
	bool operator<=(size_t number) const;
	bool operator>=(const BinaryNumber& binary_number) const;
	bool operator>=(size_t number) const;

	size_t size() const;
	size_t logicalSize() const;

	BinaryNumber& operator++();
	BinaryNumber& operator--();
	BinaryNumber& incrementDiscardCarry();
	BinaryNumber& shiftLeft(size_t amount);
	BinaryNumber& shiftRight(size_t amount);
	BinaryNumber& addTrailingZeros(size_t amount);
	BinaryNumber& addTrailingOnes(size_t amount);
	BinaryNumber& changeToOnesComplement();

	BinaryNumber operator++(int);
	BinaryNumber operator--(int);
	BinaryNumber subBinaryNumber(size_t start_index_included, size_t end_index_excluded);
	BinaryNumber getOnesComplement();

	using const_iterator = deque<bool>::const_iterator;
	const_iterator begin() const { return binary_array.begin(); }
	const_iterator end() const { return binary_array.end(); }

	static size_t matchSize(BinaryNumber& binary_number1, BinaryNumber& binary_number2);
	static size_t matchSizeEven(BinaryNumber& binary_number1, BinaryNumber& binary_number2);
	static bool isStringValidBinaryNumber(string binary_number_str);
	static BinaryNumber generateByLength(size_t length);
};