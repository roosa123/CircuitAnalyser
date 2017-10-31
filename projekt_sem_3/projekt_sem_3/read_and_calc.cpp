#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>
#include"read_and_calc.h"

read_and_calc::read_and_calc() :output_file_name(""), end_of_circuit(".END") {
	parse_it = new parser;
	matrix_G = new matrix_real;
	matrix_C = new matrix_real;
	matrix_invL = new matrix_real;
	vector_I = new vector_complex;
	vector_V = new vector_complex;
	matrix_Y = new matrix_complex;
	main_computing_object = new nodal_analyser;
}

bool read_and_calc::file_reader(string input_file_name) {
	fstream input_file;

	input_file.open(input_file_name, ios::in);

	if (!input_file.is_open()) {
		file_not_opened_check_if_no_extension(input_file_name);
		input_file.open(input_file_name, ios::in);

		if (!input_file.is_open()) {
			cout << "Nie mozna otworzyc pliku " << input_file_name << endl;
			return false;
		}
	}

	getline(input_file, output_file_name);

	if (output_file_name.empty()) {
		cout << "Plik pusty!" << endl;

		input_file.close();
		
		return false;
	}

	string buffer;

	while (true)
	{
		getline(input_file, buffer);

		if (buffer == end_of_circuit)
			break;

		parse_it->set_line(buffer);
		parse_it->parse_line();

		element got_it = *parse_it->get_element();

		if (matrix_G->get_matrix_size() < got_it.get_node_minus() || matrix_C->get_matrix_size() < got_it.get_node_minus() || matrix_invL->get_matrix_size() < got_it.get_node_minus() || vector_I->get_vector_size() < got_it.get_node_minus()) {
			matrix_G->add_node(got_it.get_node_minus());
			matrix_C->add_node(got_it.get_node_minus());
			matrix_invL->add_node(got_it.get_node_minus());
			vector_I->add_node(got_it.get_node_minus());
		}

		if (matrix_G->get_matrix_size() < got_it.get_node_plus() || matrix_C->get_matrix_size() < got_it.get_node_plus() || matrix_invL->get_matrix_size() < got_it.get_node_plus() || vector_I->get_vector_size() < got_it.get_node_plus()) {
			matrix_G->add_node(got_it.get_node_plus());
			matrix_C->add_node(got_it.get_node_plus());
			matrix_invL->add_node(got_it.get_node_plus());
			vector_I->add_node(got_it.get_node_plus());
		}

		switch (got_it.get_type()) {
		case 'R':
			matrix_G->add_value(got_it);
			break;

		case 'C':
			matrix_C->add_value(got_it);
			break;

		case 'L':
			matrix_invL->add_value(got_it);
			break;

		case 'I':
			vector_I->add_value(got_it);
			break;

		default:
			matrix_G->add_value(got_it);
			break;
		}
	}

	return true;
}

void read_and_calc::file_not_opened_check_if_no_extension(string& input_file_name) {
	if (input_file_name.at(input_file_name.size() - 4) != '.')	// is there extesion? If not, let's give default (.txt)
		input_file_name += ".txt";
	else {
		input_file_name.erase(input_file_name.size() - 3);
		input_file_name += "txt";
	}
}

void read_and_calc::create_matrix_Y(int frequency) {
	int matrix_size = matrix_C->get_matrix_size();	// also can be size of matrix_G or matrix_invL or vector_I

	if (matrix_Y->get_matrix_size() < matrix_size)
		matrix_Y->add_node(matrix_size);

	complex another_element_of_matrix_Y(0.0, 0.0);

	for (int i = 0; i < matrix_size; ++i)
		for (int j = 0; j < matrix_size; ++j) {
			another_element_of_matrix_Y.set_re(matrix_G->get_matrix_element(i, j));

			if (matrix_C->get_matrix_element(i, j) == 0 && matrix_invL->get_matrix_element(i, j) != 0)
				another_element_of_matrix_Y.set_im(matrix_invL->get_matrix_element(i, j) / (2.0 * M_PI * frequency));
			else if (matrix_C->get_matrix_element(i, j) != 0 && matrix_invL->get_matrix_element(i, j) == 0)
				another_element_of_matrix_Y.set_im(matrix_C->get_matrix_element(i, j) * 2.0 * M_PI * frequency);
			else if (matrix_C->get_matrix_element(i, j) != 0 && matrix_invL->get_matrix_element(i, j) != 0)
				another_element_of_matrix_Y.set_im(matrix_C->get_matrix_element(i, j) * 2.0 * M_PI * frequency + matrix_invL->get_matrix_element(i, j) / (2.0 * M_PI * frequency));
			else if (matrix_C->get_matrix_element(i, j) == 0 && matrix_invL->get_matrix_element(i, j) == 0)
				another_element_of_matrix_Y.set_im(0.0);

			matrix_Y->set_element(another_element_of_matrix_Y, i, j);
		}
}

vector_complex* read_and_calc::calculate_potentials() {
	vector_V->add_node(vector_I->get_vector_size());

	main_computing_object->LU_distribution(matrix_Y);
	main_computing_object->LU_analysis(vector_I, vector_V);

	return vector_V;
}

bool read_and_calc::export_a_heading_to_the_file() {
	fstream output_file;

	output_file.open(output_file_name, ios::out);

	if (!output_file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;

		return false;
	}

	output_file << "*** Wyniki obliczen (wartosci wektora potencjalow wezlowych przy roznych czestotliwosciach) ***\n\n";
	output_file << "*** Obliczenia wykonano metoda potencjalow wezlowych. Rownania macierzowe rozwiazano metoda rozkladu LU ***\n\n\n";

	output_file.close();

	return true;
}

bool read_and_calc::export_to_the_file(vector_complex* vector_V, int frequency) {
	fstream output_file;

	output_file.open(output_file_name, ios::out | ios::app);

	if (!output_file.is_open()) {
		cout << "Nie udalo sie otworzyc pliku wyjsciowego!" << endl;

		return false;
	}
	
	output_file << "Potencjaly w wezlach przy czestotliwosci " << frequency << " Hz:" << "\n";

	for (int i = 0; i < vector_V->get_vector_size(); ++i) {
		output_file << "Wezel nr " << i + 1 << ": (" << vector_V->get_element(i).get_re() << " + j" << vector_V->get_element(i).get_im() << ") V\n";
	}

	output_file.close();

	return true;
}

read_and_calc::~read_and_calc() {
	delete parse_it;
	delete matrix_G;
	delete matrix_C;
	delete matrix_invL;
	delete vector_I;
	delete vector_V;
	delete matrix_Y;
	delete main_computing_object;
}