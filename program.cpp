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
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

void readInput(const string& input_file_name, int& algorithm_identifier, string& binary_number1_str, string& binary_number2_str);
void checkInput(int algorithm_identifier, const string& binary_number1_str, const string& binary_number2_str);
void writeOutput(const string& output_file_name, const vector<BinaryNumber>& results);
void trimRight(string& str, const string& trimChars = " \f\n\r\t\v");
void trimLeft(string& str, const string& trimChars = " \f\n\r\t\v");
//void testAlgorithms(const vector<ISingleResultAlgorithm*>& single_result_algorithms, const vector<IResultPairAlgorithm*>& result_pair_algorithms);

int main(int argc, char* argv[]) {

	if (argc < 3) {
		cout << "Program arguments should be: [input file name] [output_file_name]";
		exit(EXIT_FAILURE);
	}

	vector<ISingleResultAlgorithm*> single_result_algorithms;
	vector<IResultPairAlgorithm*> result_pair_algorithms;
	vector<BinaryNumber> results;

	single_result_algorithms.push_back(new NaiveAdditionAlgorithm());
	single_result_algorithms.push_back(new LongAdditionAlgorithm());
	single_result_algorithms.push_back(new NaiveMultiplicationAlgorithm());
	single_result_algorithms.push_back(new LongMultiplicationAlgorithm());
	single_result_algorithms.push_back(new DynamicProgrammingMultiplicationAlgorithm());
	single_result_algorithms.push_back(new KaratsubaMultiplicationAlgorithm());
	result_pair_algorithms.push_back(new NaiveEuclideanDivisionAlgorithm());
	result_pair_algorithms.push_back(new BinarySearchEuclideanDivisionAlgorithm());

	int algorithm_identifier;
	string binary_number1_str;
	string binary_number2_str;

	readInput(argv[1], algorithm_identifier, binary_number1_str, binary_number2_str);
	checkInput(algorithm_identifier, binary_number1_str, binary_number2_str);

	cout << "Converting to binary numbers..." << endl;
	BinaryNumber binary_number1 = BinaryNumber(binary_number1_str);
	BinaryNumber binary_number2 = BinaryNumber(binary_number2_str);

	cout << "Beginning algorithmic calculation(s)..." << endl;
	if (algorithm_identifier < 7) {
		results.push_back(single_result_algorithms[algorithm_identifier - 1]->calculate(binary_number1, binary_number2));
	}

	else if (algorithm_identifier < 9) {
		BinaryNumber remainder = BinaryNumber(0);
		results.push_back(result_pair_algorithms[algorithm_identifier - 7]->calculate(binary_number1, binary_number2, remainder));
		results.push_back(remainder);
	}

	else {
		BinaryNumber remainder = BinaryNumber(0);
		for (ISingleResultAlgorithm* algo : single_result_algorithms) {
			results.push_back(algo->calculate(binary_number1, binary_number2));
		}
		for (IResultPairAlgorithm* algo : result_pair_algorithms) {
			results.push_back(algo->calculate(binary_number1, binary_number2, remainder));
			results.push_back(remainder);
		}
	}

	cout << "Algorithmic calculation(s) ended." << endl;

	writeOutput(argv[2], results);

	for (ISingleResultAlgorithm* algo : single_result_algorithms) {
		delete algo;
	}

	for (IResultPairAlgorithm* algo : result_pair_algorithms) {
		delete algo;
	}
}

void readInput(const string& input_file_name, int& algorithm_identifier, string& binary_number1_str, string& binary_number2_str) {
	ifstream input_file;
	input_file.open(input_file_name, ios::in);
	bool failed = false;

	if (!input_file.is_open()) {
		cout << "Input file is empty.\nMust contain algorithm number (1-9) and 2 binary numbers" << endl;
		failed = true;
	}

	if (!failed && input_file.eof()) {
		cout << "Could not read algorithm number (must be on the first line and between 1 and 9)" << endl;
		failed = true;
	}

	else {
		string algorithm_identifier_str;
		getline(input_file, algorithm_identifier_str);

		try {
			algorithm_identifier = stoi(algorithm_identifier_str);
		}
		catch (exception& ex) {
			cout << "Could not read algorithm number (must be on the first line and between 1 and 9)" << endl;
			failed = true;
		}
	}

	if (!failed && input_file.eof()) {
		cout << "Input file does not contain any binary numbers.\nMust contain 2 binary numbers on the first and second lines" << endl;
		failed = true;
	}

	else {
		getline(input_file, binary_number1_str);
		trimLeft(binary_number1_str);
		trimRight(binary_number1_str);
	}

	if (!failed && input_file.eof()) {
		cout << "Input file does not contain a second binary number.\nMust contain 2 binary numbers on the first and second lines" << endl;
		failed = true;
	}

	else {
		getline(input_file, binary_number2_str);
		trimLeft(binary_number2_str);
		trimRight(binary_number2_str);
	}

	input_file.close();

	if (failed) {
		exit(EXIT_FAILURE);
	}
}

void checkInput(int algorithm_identifier, const string& binary_number1_str, const string& binary_number2_str) {
	bool failed = false;
	
	if (algorithm_identifier < 1 || algorithm_identifier > 9) {
		cout << "Algorithm number (on first line of input file) must be between 1 and 9" << endl;
		failed = true;
	}

	if (!BinaryNumber::isStringValidBinaryNumber(binary_number1_str)) {
		cout << "The first binary number provided is not valid (must start with 1 and follow with only 0s and 1s, or be 0)" << endl;
		failed = true;
	}

	if (!BinaryNumber::isStringValidBinaryNumber(binary_number2_str)) {
		cout << "The second binary number provided is not valid (must start with 1 and follow with only 0s and 1s, or be 0)" << endl;
		failed = true;
	}

	if (failed) {
		exit(EXIT_FAILURE);
	}
}

void writeOutput(const string& output_file_name, const vector<BinaryNumber>& results) {
	ofstream output_file;
	output_file.open(output_file_name, ios::out);

	if (!output_file.is_open()) {
		cout << "Failed to open output file";
		exit(EXIT_FAILURE);
	}

	else {
		int i;
		for (i = 0; i < results.size() - 1; i++) {
			output_file << results[i] << endl;
		}
		output_file << results[i];
	}
}

void trimRight(string& str, const string& trimChars)
{
	std::string::size_type pos = str.find_last_not_of(trimChars);
	str.erase(pos + 1);
}


void trimLeft(string& str, const string& trimChars)
{
	std::string::size_type pos = str.find_first_not_of(trimChars);
	str.erase(0, pos);
}

//N of algo 1: 32
//N of algo 2: 536870912
//N of algo 3: 32
//N of algo 4: 32768
//N of algo 5: 32768
//N of algo 6: 32768
//N of algo 7: 32
//N of algo 8: 512
// 
//void testAlgorithms(const vector<ISingleResultAlgorithm*>& single_result_algorithms, const vector<IResultPairAlgorithm*>& result_pair_algorithms) {
//	using namespace std::chrono;
//	srand(time(0));
//	int curr_algorithm_identifier = 3;
//	size_t length;
//	double elapsed_time_millis;
//
//	for (ISingleResultAlgorithm* algo : single_result_algorithms) {
//		curr_algorithm_identifier++;
//		elapsed_time_millis = 0;
//		length = 2;
//
//		BinaryNumber result = BinaryNumber(0);
//
//		while (elapsed_time_millis / 1000 / 60 < 5) {
//			BinaryNumber binary_number1 = BinaryNumber::generateByLength(length);
//			BinaryNumber binary_number2 = BinaryNumber::generateByLength(length);
//
//			cout << "Testing algorithm: " << curr_algorithm_identifier << " with binary number length: " << length << endl;
//			//cout << "Chosen binary numbers:" << endl << "(1): " << binary_number1 << endl << "(2): " << binary_number2 << endl;
//			auto start = high_resolution_clock::now();
//			result = algo->calculate(binary_number1, binary_number2);
//			auto end = high_resolution_clock::now();
//
//			elapsed_time_millis = duration<double, std::milli>(end - start).count();
//			//cout << "Result: " << result << endl;
//			cout << "Elapsed time: " << elapsed_time_millis / 1000 / 60 << " minutes" << endl;
//
//			length = length *= 2;
//		}
//	}
//
//	for (IResultPairAlgorithm* algo : result_pair_algorithms) {
//		curr_algorithm_identifier++;
//		elapsed_time_millis = 0;
//		length = 2;
//
//		BinaryNumber quotient = BinaryNumber(0);
//		BinaryNumber remainder = BinaryNumber(0);
//
//		while (elapsed_time_millis / 1000 / 60 < 5) {
//			BinaryNumber binary_number2 = BinaryNumber::generateByLength(length);
//			BinaryNumber binary_number2_squared = KaratsubaMultiplicationAlgorithm().calculate(binary_number2, binary_number2);
//			BinaryNumber binary_number1 = BinaryNumber(0);
//
//			do {
//				binary_number1 = BinaryNumber::generateByLength(binary_number2_squared.size());
//			} while (binary_number1 <= binary_number2_squared);
//
//
//			cout << "Testing algorithm: " << curr_algorithm_identifier << " with binary number length: " << length << endl;
//			//cout << "Chosen binary numbers:" << endl << "(1): " << binary_number1 << endl << "(2): " << binary_number2 << endl;
//
//			auto start = high_resolution_clock::now();
//			quotient = algo->calculate(binary_number1, binary_number2, remainder);
//			auto end = high_resolution_clock::now();
//
//			elapsed_time_millis = duration<double, std::milli>(end - start).count();
//			
//			//cout << "Quotient: " << quotient << " | Remainder: " << remainder << endl;
//			cout << "Elapsed time: " << elapsed_time_millis / 1000 / 60 << " minutes" << endl;
//
//			length *= 2;
//		}
//	}
//}