#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using namespace std;

class BinaryNumber {

private:
	vector<bool> binary_array;

	friend ostream& operator<<(ostream& os, const BinaryNumber& binary_number);

	size_t countTrailingZeros() const;
	void fromDecimalRec(size_t number);

public:
	BinaryNumber(size_t number);
	BinaryNumber(initializer_list<unsigned char> binary_array_values);
	BinaryNumber(const string& binary_string);

	bool operator[](size_t index) const;
	bool operator==(const BinaryNumber& binary_number);

	size_t size() const;
	size_t logicalSize() const;

	using const_iterator = vector<bool>::const_iterator;
	const_iterator begin() const { return binary_array.begin(); }
	const_iterator end() const { return binary_array.end(); }

};