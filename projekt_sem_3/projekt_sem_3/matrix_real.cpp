#define _USE_MATH_DEFINES

#include<cmath>
#include"matrix_real.h"

matrix_real::matrix_real() :node_counter(0), matrix(nullptr) {}

matrix_real::matrix_real(int node_amount) : node_counter(node_amount) {
	matrix = new double*[node_amount];

	for (int i = 0; i < node_amount; ++i)
		matrix[i] = new double[node_amount];

	for (int i = 0; i < node_amount; ++i)
		for (int j = 0; j < node_amount; ++j)
			matrix[i][j] = 0;
}

void matrix_real::add_node(int new_size) {
	double** matrix_tmp = new double*[new_size];

	for (int i = 0; i < new_size; ++i) {
		matrix_tmp[i] = new double[new_size];

		for (int j = 0; j < new_size; ++j)
			matrix_tmp[i][j] = 0.0;
	}

	for (int i = 0; i < node_counter; ++i) {
		for (int j = 0; j < node_counter; ++j)
			matrix_tmp[i][j] = matrix[i][j];

		delete[] matrix[i];
	}

	node_counter = new_size;
	delete[] matrix;
	matrix = matrix_tmp;
}


void matrix_real::add_value(element new_element) {
	switch (new_element.get_type()) {
	case 'R':
		if (new_element.get_node_minus() == 0)
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += 1 / new_element.get_value();

		else if (new_element.get_node_plus() == 0)
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += 1 / new_element.get_value();

		else {
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += 1 / new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += 1 / new_element.get_value();
			matrix[new_element.get_node_plus() - 1][new_element.get_node_minus() - 1] -= 1 / new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_plus() - 1] -= 1 / new_element.get_value();
		}

		break;
	case 'L':
		if (new_element.get_node_minus() == 0)
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += 1 / new_element.get_value();

		else if (new_element.get_node_plus() == 0)
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += 1 / new_element.get_value();

		else {
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += 1 / new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += 1 / new_element.get_value();
			matrix[new_element.get_node_plus() - 1][new_element.get_node_minus() - 1] -= 1 / new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_plus() - 1] -= 1 / new_element.get_value();
		}
		break;
	case 'C':
		if (new_element.get_node_minus() == 0)
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += new_element.get_value();

		else if (new_element.get_node_plus() == 0)
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += new_element.get_value();

		else {
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += new_element.get_value();
			matrix[new_element.get_node_plus() - 1][new_element.get_node_minus() - 1] -= new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_plus() - 1] -= new_element.get_value();
		}
		break;
	default:
		if (new_element.get_node_minus() == 0)
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += 1 / new_element.get_value();

		else if (new_element.get_node_plus() == 0)
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += 1 / new_element.get_value();

		else {
			matrix[new_element.get_node_plus() - 1][new_element.get_node_plus() - 1] += 1 / new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_minus() - 1] += 1 / new_element.get_value();
			matrix[new_element.get_node_plus() - 1][new_element.get_node_minus() - 1] -= 1 / new_element.get_value();
			matrix[new_element.get_node_minus() - 1][new_element.get_node_plus() - 1] -= 1 / new_element.get_value();
		}
		break;
	}
}

double matrix_real::get_matrix_element(int i_row, int j_column) {
	return matrix[i_row][j_column];
}

int matrix_real::get_matrix_size() {
	return node_counter;
}

/*
complex matrix_real::calculate_values(char type_of_element, double value_of_element, double frequency) {
	complex complex_admittance;

	if (value_of_element == 0) {
		complex_admittance.set_re(0);
		complex_admittance.set_im(0);
		return complex_admittance;
	}

	switch (type_of_element) {
	case 'R':
		complex_admittance.set_re(value_of_element);
		break;

	case 'L':
		complex_admittance.set_im(value_of_element));
		break;

	case 'C':
		complex_admittance.set_im(value_of_element);
		break;

	default:
		complex_admittance.set_re(0);
		complex_admittance.set_im(0);
		break;
	}

	return complex_admittance;
}
*/
matrix_real::~matrix_real() {
	for (int i = 0; i < node_counter; i++)
		delete[] matrix[i];

	delete[] matrix;
}