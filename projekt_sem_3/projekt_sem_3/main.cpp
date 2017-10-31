#include<iostream>
#include"cmd_args.h"
#include"read_and_calc.h"

using namespace std;

int main(int argc, char* argv[]) {
	cmd_args cmd_line_args;

	bool is_called_ok = cmd_line_args.get_and_set_cmd_args(argc, argv);

	if (!is_called_ok) {
		cout << "Program niepoprawnie uruchomiony!" << endl;
		
		system("pause");
		return 0;
	}

	read_and_calc I_ll_do_anything_user_wants;

	bool has_the_file_opened = I_ll_do_anything_user_wants.file_reader(cmd_line_args.get_input_file_name());

	if (!has_the_file_opened) {
		system("pause");
		return 0;
	}


	int f_start = 100;
	int f_stop = 1100;

	vector_complex* vector_of_potentials;

	I_ll_do_anything_user_wants.export_a_heading_to_the_file();

	for (int f = f_start; f < f_stop; f += 100) {
		I_ll_do_anything_user_wants.create_matrix_Y(f);
		vector_of_potentials = I_ll_do_anything_user_wants.calculate_potentials();

		I_ll_do_anything_user_wants.export_to_the_file(vector_of_potentials, f);
	}

	return 0;
}