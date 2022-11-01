#include "functions.h"


using namespace std;

void read_sequence_of_number(vector<int>* input) {
	string temp_seq;
	cout << "\nGive the sequence:";
	cin >> temp_seq;
	input->resize(temp_seq.length());
	for (int i = 0; i < temp_seq.length(); i++)
		input->at(i) = temp_seq[i] - '0';
}

void print_vector(vector<int> M) {

	cout << "\n";
	for (int i = 0; i < M.size(); i++)
		cout << M.at(i);
}

void apply_even_parity(vector<int>* input) {
	int sum = 0;
	for (int i = 0; i < input->size(); i++)
		sum = sum + input->at(i);
	input->push_back(sum % 2);
}

void check_even_parity_of_received_message(vector<int> M) {
	int sum = 0;
	for (int i = 0; i < M.size(); i++)
		sum = sum + M[i];
	if (sum % 2)
		cout << "\nThere is an error\n";
	else
		cout << "\nThere is not any error detected\n";
}

void apply_noise_to_a_sequence(vector<int> noise_index, vector<int> M, vector<int>* output) {

	for (int i = 0; i < noise_index.size(); i++) {
		if (noise_index[i] > M.size()) {
			cout << "\nThe noise index that you gave are out of bounds!\n";
			return;
		}
		M.at(noise_index[i]) = (M.at(noise_index[i]) + 1) % 2;
	}
	output->resize(M.size());
	for (int i = 0; i < M.size(); i++)
		output->at(i) = M[i];
}

void read_28_bit_sequence_of_number(vector<vector<int>>* M) {
	cout << "\nGive the 28-bit sequence by typing 7-bit the time";
	for(int i = 0; i<4;i++)
		read_sequence_of_number( &(M->at(i)) );

}

void print_vector_of_vectors(vector<vector<int>> M) {
	for (int i = 0; i < M.size(); i++)
		print_vector(M[i]);
}

void apply_double_even_parity(vector<vector<int>>* M) {
	M->resize(M->size() + 1);
	(M->at(M->size() - 1)).resize((M->at(0)).size() + 1);
	int depth = M->size() - 1;
	int breadth = (M->at(0)).size();
	for (int i = 0; i < depth ; i++) {
		int sum_row = 0;
		for (int j = 0; j < breadth ; j++) {
			sum_row = sum_row + (M->at(i)).at(j);
		}
		(M->at(i)).push_back(sum_row % 2);
	}
	for (int i = 0; i < breadth + 1; i++) {
		int sum_column = 0;
		for (int j = 0; j < depth; j++)
			sum_column = sum_column + (M->at(j)).at(i);
		(M->at(depth)).at(i) = sum_column % 2;
	}
}

void apply_noise_to_a_sequence2(std::vector<std::vector<int>> noise_index, std::vector<std::vector<int>> M, std::vector<std::vector<int>>* output) {

	for (int i = 0; i < noise_index.size(); i++) {
		(M[noise_index[i][0]])[noise_index[i][1]] = ((M[noise_index[i][0]])[noise_index[i][1]] + 1) % 2;
	}
	output->resize(M.size());
	for (int i = 0; i < M.size(); i++) {
		(output->at(i)).resize(M[0].size());
		for (int j = 0; j < M[0].size(); j++) {
			(output->at(i))[j] = (M[i])[j];
		}
	}
}

void check_double_even_parity_of_received_message(std::vector<std::vector<int>> M) {
	vector<int> possible_positions_of_error;
	for (int i = 0; i < M.size(); i++) {
		possible_positions_of_error.resize(0);
		possible_positions_of_error.shrink_to_fit();
		for (int j = 0; j < M[0].size(); j++) {
			int row_sum = 0;
			int column_sum = 0;
			for (int k = 0; k < M[0].size(); k++) {
				row_sum = row_sum + (M[i])[k];
			}
			for (int k = 0; k < M.size(); k++) {
				column_sum = column_sum + (M[k])[j];
			}
			row_sum = row_sum % 2;
			column_sum = column_sum % 2;
			if ((row_sum == 1) && (column_sum == 1))
				cout << "\n\nThere is an error at " << i + 1 << " row and " << j + 1 << " column";
			else if ((row_sum == 0) && (column_sum == 1)) {
				possible_positions_of_error.push_back(j);
			}
		}
		if (possible_positions_of_error.size() > 1) {
			cout << "\nThere are errors at a certain row and at columns:";
			for(int z = 0; z < possible_positions_of_error.size(); z++) {
				cout<<possible_positions_of_error.at(z) +1 << ",";
			}
		}
	}
}