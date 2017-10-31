#pragma once

#include"matrix_complex.h"
#include"vector_complex.h"

class nodal_analyser {
	matrix_complex* matrix_L;
	matrix_complex* matrix_U;
	vector_complex* vector_H;

	int size_of_matrix;

public:
	nodal_analyser();
	nodal_analyser(int);
	
	void LU_distribution(matrix_complex*);
	void LU_analysis(vector_complex*, vector_complex*);

	~nodal_analyser();
};