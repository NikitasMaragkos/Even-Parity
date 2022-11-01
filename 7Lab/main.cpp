#include "functions.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
	int loop = 1;
	int choice, n, k;
	float error_rate;
	vector<int> original_input;//{ 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0 };
	vector<int> noisy_input;// (14, 0);
	vector<int> output;// (14, 0);
	vector<int> noise_index1{ 5 };
	vector<int> noise_index2{ 5, 11 };
	vector<vector<int>> orig_input;/* { { 1, 1, 0, 0, 1, 1, 1 },
						 { 1, 0, 1, 1, 1, 0, 1 },
						 { 0, 1, 1, 1, 0, 0, 1 },
						 { 0, 1, 0, 1, 0, 0, 1 } };*/
	vector<vector<int>> noise1{ {1,2} };
	vector<vector<int>> noise2{ {1,2}, {1,4} };
	vector<vector<int>> result;
	vector<int> M, F, T1, T2, P;
	string p_as_string;
	unsigned long long m, f, t1, t2, p;        //The corresponding integer numbers of M, F, T, P for less calculations. t1 is before the transmission.
	int number_of_none_error, number_of_detection_error, number_of_undetected_error;
	int total_transmitions;




	while (loop) {

		cout << "\n~~~~~~~~~~~MENU~~~~~~~~~~~\n"
			<< "0. Exit programm\n"
			<< "1. Adjust the message with even parity and output the result.\n"
			<< "2. Check errors with even parity and apply exercise's examples.\n"
			<< "3. Apply double even parity on 28-bit message and test exercise's example.\n"
			<< "4. Check errors with even parity and apply exercise's examples.\n"
			<< "\nYour choice:";
		cin >> choice;

		switch (choice) {
		case 0:
			return 0;
		case 1:
			read_sequence_of_number(&original_input);
			cout << "\nThe original message was:";
			print_vector(original_input);
			apply_even_parity(&original_input);
			cout << "\nAfter the effect of even parity it is:";
			print_vector(original_input);
			original_input.resize(0);
			original_input.shrink_to_fit();
			break;
		case 2:
			read_sequence_of_number(&original_input);
			apply_even_parity(&original_input);
			cout << "\nMessage received:";
			print_vector(original_input);
			check_even_parity_of_received_message(original_input);
			apply_noise_to_a_sequence(noise_index1, original_input , &output);
			cout << "\nMessage received:";
			print_vector(output);
			check_even_parity_of_received_message(output);
			apply_noise_to_a_sequence(noise_index2, original_input, &output);
			cout << "\nMessage received:";
			print_vector(output);
			check_even_parity_of_received_message(output);
			original_input.resize(0);
			original_input.shrink_to_fit();
			output.resize(0);
			output.shrink_to_fit();
			break;
		case 3:
			orig_input.resize(4);
			read_28_bit_sequence_of_number(&orig_input);
			cout << "\nThe original message was:\n";
			print_vector_of_vectors(orig_input);
			apply_double_even_parity(&orig_input);
			cout << "\nThe message after the apply of double even parity is:\n";
			print_vector_of_vectors(orig_input);
			orig_input.resize(0);
			orig_input.shrink_to_fit();
			break;
		case 4:
			orig_input.resize(4);
			read_28_bit_sequence_of_number(&orig_input);
			apply_double_even_parity(&orig_input);
			cout << "\n\nThe original message was:\n";
			print_vector_of_vectors(orig_input);
			cout << "\n\nMessage received:\n";
			print_vector_of_vectors(orig_input);
			check_double_even_parity_of_received_message(orig_input);


			apply_noise_to_a_sequence2(noise1, orig_input, &result);
			cout << "\n\nThe original message was:\n";
			print_vector_of_vectors(orig_input);
			cout << "\n\nMessage received:\n";
			print_vector_of_vectors(result);
			check_double_even_parity_of_received_message(result);

			apply_noise_to_a_sequence2(noise2, orig_input, &result);
			cout << "\n\nThe original message was:\n";
			print_vector_of_vectors(orig_input);
			cout << "\n\nMessage received:\n";
			print_vector_of_vectors(result);
			check_double_even_parity_of_received_message(result);

			orig_input.resize(0);
			orig_input.shrink_to_fit();
			result.resize(0);
			result.shrink_to_fit();

			break;

		}

	}


	return 0;
}