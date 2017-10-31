#pragma once

#include"vector_numbers.h"

class matrix_complex :public vector_numbers {
	static int node_i_row;
	static int node_j_col;
	complex** matrix;

public:
	matrix_complex();
	matrix_complex(int);

	complex get_element(int, int);
	void set_element(complex, int, int);
	void add_node(int);
	void add_value(complex);
	int get_matrix_size();

	~matrix_complex();
};