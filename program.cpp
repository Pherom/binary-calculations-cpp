#include "binary_number.h"
#include "single_result_algorithm.h"
#include "naive_addition_algorithm.h"
#include "long_addition_algorithm.h"
#include "naive_multiplication_algorithm.h"
#include "long_multiplication_algorithm.h"
#include "dynamic_programming_multiplication_algorithm.h"
#include "karatsuba_multiplication_algorithm.h"
#include <vector>

int main(int argc, char* argv[]) {
	vector<ISingleResultAlgorithm*> algorithms;
	algorithms.push_back(new NaiveAdditionAlgorithm());
	algorithms.push_back(new LongAdditionAlgorithm());
	algorithms.push_back(new NaiveMultiplicationAlgorithm());
	algorithms.push_back(new LongMultiplicationAlgorithm());
	algorithms.push_back(new DynamicProgrammingMultiplicationAlgorithm());
	algorithms.push_back(new KaratsubaMultiplicationAlgorithm());

	BinaryNumber binary_number1("11111");
	BinaryNumber binary_number2("111");
	cout << algorithms[5]->calculate(binary_number1, binary_number2);

	for (ISingleResultAlgorithm* algo : algorithms) {
		delete algo;
	}
}