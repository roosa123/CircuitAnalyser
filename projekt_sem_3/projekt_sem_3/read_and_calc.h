#pragma once

#include<fstream>
#include<string>
#include"parser.h"
#include"vector_complex.h"
#include"matrix_real.h"
#include"matrix_complex.h"
#include"nodal_analyser.h"

using namespace std;

class read_and_calc {
	fstream input_file;
	parser* parse_it;
	string output_file_name;
	const string end_of_circuit;

	matrix_real* matrix_G;
	matrix_real* matrix_C;
	matrix_real* matrix_invL;
	matrix_complex* matrix_Y;
	vector_complex* vector_I;
	vector_complex* vector_V;
	nodal_analyser* main_computing_object;

public:
	read_and_calc();

	bool file_reader(string);
	void file_not_opened_check_if_no_extension(string&);
	void create_matrix_Y(int);
	vector_complex* calculate_potentials();
	bool export_a_heading_to_the_file();
	bool export_to_the_file(vector_complex*, int);

	~read_and_calc();
};