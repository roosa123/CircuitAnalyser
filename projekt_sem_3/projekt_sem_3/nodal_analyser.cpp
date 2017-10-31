#include"nodal_analyser.h"

nodal_analyser::nodal_analyser() :size_of_matrix(0) {
	matrix_L = new matrix_complex;
	matrix_U = new matrix_complex;
	vector_H = new vector_complex;
}

nodal_analyser::nodal_analyser(int matrix_size) : size_of_matrix(matrix_size) {
	matrix_L = new matrix_complex(matrix_size);
	matrix_U = new matrix_complex(matrix_size);
	vector_H = new vector_complex(matrix_size);
}

void nodal_analyser::LU_distribution(matrix_complex* matrix_Y) {
	complex sum;
	size_of_matrix = matrix_Y->get_matrix_size();

	if(matrix_L->get_matrix_size() < size_of_matrix)
		matrix_L->add_node(size_of_matrix);

	if(matrix_U->get_matrix_size() < size_of_matrix)
		matrix_U->add_node(size_of_matrix);

	for (int i = 0; i < size_of_matrix; ++i)
		matrix_L->set_element(1.0, i, i);

	for (int i = 0; i < size_of_matrix; ++i) {
		for (int j = i; j < size_of_matrix; ++j) {
			sum.set_re(0.0);
			sum.set_im(0.0);

			for (int k = 0; k < i; ++k)
				sum += matrix_L->get_element(i, k) * matrix_U->get_element(k, j);

			matrix_U->set_element(matrix_Y->get_element(i, j) - sum, i, j);
		}
		
		for (int j = i + 1; j < size_of_matrix; ++j) {
			sum.set_re(0.0);
			sum.set_im(0.0);

			for (int k = 0; k < i; ++k)
				sum += matrix_L->get_element(j, k) * matrix_U->get_element(k, i);

			matrix_L->set_element((matrix_Y->get_element(j, i)) / matrix_U->get_element(i, i), j, i);
		}
	}
}

void nodal_analyser::LU_analysis(vector_complex* vector_I, vector_complex* vector_V) {
	complex sum;

	if (vector_H->get_vector_size() < size_of_matrix)
		vector_H->add_node(size_of_matrix);

	for (int i = 0; i < size_of_matrix; ++i) {
		sum.set_re(0.0);
		sum.set_im(0.0);

		for (int k = 0; k < i; ++k)
			sum += matrix_L->get_element(i, k) * vector_H->get_element(k);

		vector_H->set_element(vector_I->get_element(i) - sum, i);
	}

	for (int i = size_of_matrix - 1; i >= 0; --i) {
		sum.set_re(0.0);
		sum.set_im(0.0);

		for (int k = i + 1; k < size_of_matrix; ++k)
			sum += matrix_U->get_element(i, k) * vector_V->get_element(k);
		
		vector_V->set_element((vector_H->get_element(i) - sum) / matrix_U->get_element(i, i), i);
	}
}

nodal_analyser::~nodal_analyser() {
	delete matrix_L;
	delete matrix_U;
	delete vector_H;
}