#include"cmd_args.h"

using namespace std;

//cmd_args::cmd_args() :input_file_name(0) {}

bool cmd_args::get_and_set_cmd_args(int number_of_args, char** args) {
	const string TAG_INPUT("-i"); // flag for only available switch
	int tag_position = 1;
	int default_args = 3;

	if (number_of_args < default_args) {
		return false;
	}

	if (args[tag_position] == TAG_INPUT) {
		input_file_name = args[tag_position + 1];
		return true;
	}
	else
		return false;
}

string cmd_args::get_input_file_name() {
	return input_file_name;
}