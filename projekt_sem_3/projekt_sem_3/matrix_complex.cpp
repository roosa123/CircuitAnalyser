#include"matrix_complex.h"

matrix_complex::matrix_complex() :vector_numbers(), matrix(nullptr) {}

int matrix_complex::node_i_row(0);
int matrix_complex::node_j_col(0);

matrix_complex::matrix_complex(int node_amount) : vector_numbers(node_amount) {
	matrix = new complex*[node_amount];

	for (int i = 0; i < node_amount; ++i)
		matrix[i] = new complex[node_amount];

	node_counter = node_amount;
}

complex matrix_complex::get_element(int i_row, int j_column) {
	return matrix[i_row][j_column];
}

void matrix_complex::set_element(complex value_to_set, int i_row, int j_column) {
	matrix[i_row][j_column] = value_to_set;
}

void matrix_complex::add_node(int new_size) {
	complex** matrix_tmp = new complex*[new_size];

	for (int i = 0; i < new_size; ++i)
		matrix_tmp[i] = new complex[new_size];

	for (int i = 0; i < node_counter; ++i)
		delete[] matrix[i];

	node_counter = new_size;
	delete[] matrix;
	matrix = matrix_tmp;
}

void matrix_complex::add_value(complex new_value) {
	matrix[node_i_row][node_j_col] += new_value;
}

int matrix_complex::get_matrix_size() {
	return node_counter;
}

matrix_complex::~matrix_complex() {
	for (int i = 0; i < node_counter; i++)
		delete[] matrix[i];
	
	delete[] matrix;
}