#include "binary_number.h"
#include "single_result_algorithm.h"
#include "result_pair_algorithm.h"
#include "naive_addition_algorithm.h"
#include "long_addition_algorithm.h"
#include "naive_multiplication_algorithm.h"
#include "long_multiplication_algorithm.h"
#include "dynamic_programming_multiplication_algorithm.h"
#include "karatsuba_multiplication_algorithm.h"
#include "naive_euclidean_division_algorithm.h"
#include "binary_search_euclidean_division_algorithm.h"
#include <vector>

int main(int argc, char* argv[]) {
	vector<ISingleResultAlgorithm*> single_result_algorithms;
	vector<IResultPairAlgorithm*> result_pair_algorithms;
	single_result_algorithms.push_back(new NaiveAdditionAlgorithm());
	single_result_algorithms.push_back(new LongAdditionAlgorithm());
	single_result_algorithms.push_back(new NaiveMultiplicationAlgorithm());
	single_result_algorithms.push_back(new LongMultiplicationAlgorithm());
	single_result_algorithms.push_back(new DynamicProgrammingMultiplicationAlgorithm());
	single_result_algorithms.push_back(new KaratsubaMultiplicationAlgorithm());
	result_pair_algorithms.push_back(new NaiveEuclideanDivisionAlgorithm());
	result_pair_algorithms.push_back(new BinarySearchEuclideanDivisionAlgorithm());

	BinaryNumber binary_number1("1000111110001111111110001111110011110000001111111111100011111111011111101111111111110111111111111110000111110000111111000001111111111111111");
	BinaryNumber binary_number2("1110011010111001101011100110101110011010111001101011100110101110011010111001101011100110101110011010111001101011100110101110011010");
	BinaryNumber remainder = BinaryNumber(0);
	cout << result_pair_algorithms[1]->calculate(binary_number1, binary_number2, remainder) << endl << endl;
	cout << remainder;

	for (ISingleResultAlgorithm* algo : single_result_algorithms) {
		delete algo;
	}

	for (IResultPairAlgorithm* algo : result_pair_algorithms) {
		delete algo;
	}
}