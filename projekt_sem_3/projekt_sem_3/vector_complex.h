#pragma once
#include"vector_numbers.h"
#include"element.h"

class vector_complex : public vector_numbers {
protected:
	complex* vector;

public:
	vector_complex();
	vector_complex(int);
	//vector_complex(int, complex);
	//vector_complex(int, complex, complex);

	void add_node(int);
	void add_value(element);
	int get_vector_size();
	complex get_element(int);
	void set_element(complex, int);

	~vector_complex();
};