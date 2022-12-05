#include "binary_number.h"
#include "algorithm.h"
#include "naive_addition_algorithm.h"
#include <vector>

int main(int argc, char* argv[]) {
	vector<IAlgorithm*> algorithms;
	algorithms.push_back(new NaiveAdditionAlgorithm());

	BinaryNumber binary_number1(17);
	BinaryNumber binary_number2("0001");
	cout << algorithms[0]->calculate(binary_number1, binary_number2);

	for (IAlgorithm* algo : algorithms) {
		delete algo;
	}
}