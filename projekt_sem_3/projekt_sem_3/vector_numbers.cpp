#include"vector_numbers.h"

vector_numbers::vector_numbers() :node_counter(0) {}

vector_numbers::vector_numbers(int primary_nodes) : node_counter(primary_nodes) {}

vector_numbers::~vector_numbers(){
	node_counter = 0;
}