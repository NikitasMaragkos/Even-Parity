#pragma once
#include<vector>
#include<string>
#include <stdio.h>
#include <iostream>
#include <time.h>


void read_sequence_of_number( std::vector<int>* M);

void print_vector(std::vector<int> M);

void apply_even_parity(std::vector<int>* input);

void check_even_parity_of_received_message(std::vector<int> M);

void apply_noise_to_a_sequence(std::vector<int> noise_index, std::vector<int> M, std::vector<int>* output);

void read_28_bit_sequence_of_number(std::vector<std::vector<int>>* M);

void print_vector_of_vectors(std::vector<std::vector<int>> M);

void apply_double_even_parity(std::vector<std::vector<int>>* M);

void apply_noise_to_a_sequence2(std::vector<std::vector<int>> noise_index, std::vector<std::vector<int>> M, std::vector<std::vector<int>>* output);

void check_double_even_parity_of_received_message(std::vector<std::vector<int>> M);