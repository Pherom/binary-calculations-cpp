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
	void changeByOne(CHANGE_BY_ONE_OPERATION operation);

public:
	BinaryNumber(size_t number);
	BinaryNumber(const string& binary_string);
	BinaryNumber(const BinaryNumber& binary_number);

	bool operator[](size_t index) const;
	bool operator==(const BinaryNumber& binary_number) const;
	bool operator==(size_t number) const;
	bool operator!=(const BinaryNumber& binary_number) const;
	bool operator!=(size_t number) const;

	size_t size() const;
	size_t logicalSize() const;

	BinaryNumber& operator++();
	BinaryNumber& operator--();

	BinaryNumber operator++(int);
	BinaryNumber operator--(int);

	using const_iterator = deque<bool>::const_iterator;
	const_iterator begin() const { return binary_array.begin(); }
	const_iterator end() const { return binary_array.end(); }

};