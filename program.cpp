#include "binary_number.h"
#include "algorithm.h"
#include "naive_addition_algorithm.h"
#include "long_addition_algorithm.h"
#include <vector>

int main(int argc, char* argv[]) {
	vector<IAlgorithm*> algorithms;
	algorithms.push_back(new NaiveAdditionAlgorithm());
	algorithms.push_back(new LongAdditionAlgorithm());

	BinaryNumber binary_number1("11111");
	BinaryNumber binary_number2("111");
	cout << algorithms[1]->calculate(binary_number1, binary_number2);

	for (IAlgorithm* algo : algorithms) {
		delete algo;
	}
}