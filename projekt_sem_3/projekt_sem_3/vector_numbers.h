#pragma once
#include"complex.h"

class vector_numbers {
protected:
	int node_counter;

public:
	vector_numbers();
	vector_numbers(int);

	void virtual add_node(int) = 0;

	virtual ~vector_numbers();
};