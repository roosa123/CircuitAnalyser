#pragma once

#include"vector_numbers.h"
#include"complex.h"
#include"element.h"

class matrix_real {
	int node_counter;
	double** matrix;

public:
	matrix_real();
	matrix_real(int);

	void add_node(int);
	void add_value(element);
	double get_matrix_element(int, int);
	int get_matrix_size();

	~matrix_real();
};