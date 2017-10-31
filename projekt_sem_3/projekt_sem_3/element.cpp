#include"element.h"

element::element() :type(0), name(""), value(0), node_plus(0), node_minus(0), data_correct(true) {}

element::element(const element& element_to_copy): type(element_to_copy.type), name(element_to_copy.name), value(element_to_copy.value), node_plus(element_to_copy.node_plus), node_minus(element_to_copy.node_minus) {}

void element::set_type(char type_to_set) {
	type = type_to_set;
}

void element::set_name(string name_to_set) {
	name = name_to_set;
}

void element::set_value(double value_to_set) {
	value = value_to_set;
}

void element::set_node_plus(int node_plus_to_set) {
	node_plus = node_plus_to_set;
}

void element::set_node_minus(int node_minus_to_set) {
	node_minus = node_minus_to_set;
}

void element::set_if_data_incorrect() {
	data_correct = false;
}

char element::get_type() {
	return type;
}

string element::get_name() {
	return name;
}

double element::get_value() {
	return value;
}

int element::get_node_plus() {
	return node_plus;
}

int element::get_node_minus() {
	return node_minus;
}

bool element::get_data_control() {
	return data_correct;
}