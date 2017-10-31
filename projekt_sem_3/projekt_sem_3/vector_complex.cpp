#include"vector_complex.h"

vector_complex::vector_complex() :vector(nullptr), vector_numbers(0) {}

vector_complex::vector_complex(int primary_node) :vector_numbers(1) {
	vector = new complex[primary_node];
}

//vector_complex::vector_complex(int primary_nodes, complex new_node) : vector_numbers(primary_nodes) {
//	vector = new complex[1];
//	vector[0] = new_node;
//}
//
//vector_complex::vector_complex(int primary_nodes, complex new_node, complex another_new_node) : vector_numbers(primary_nodes) {
//	vector = new complex[2];
//	vector[0] = new_node;
//	vector[0] = another_new_node;
//}

void vector_complex::add_node(int new_size) {
	complex* vector_tmp = new complex[new_size];

	for (int i = 0; i < node_counter; ++i)
		vector_tmp[i] = vector[i];

	node_counter = new_size;
	delete[] vector;
	vector = vector_tmp;
}

void vector_complex::add_value(element new_element) {
	if(new_element.get_node_minus() != 0)
		vector[new_element.get_node_minus() - 1].set_re(vector[new_element.get_node_minus() - 1].get_re() + new_element.get_value());

	if(new_element.get_node_plus() != 0)
		vector[new_element.get_node_plus() - 1].set_re(vector[new_element.get_node_plus() - 1].get_re() - new_element.get_value());
}

int vector_complex::get_vector_size() {
	return node_counter;
}

complex vector_complex::get_element(int element_no) {
	return vector[element_no];
}

void vector_complex::set_element(complex value_of_element, int element_no) {
	vector[element_no] = value_of_element;
}

vector_complex::~vector_complex() {
	delete[] vector;
}