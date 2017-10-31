#pragma once
#include<string>

using namespace std;

class cmd_args {
	string input_file_name;

public:
	//cmd_args();

	bool get_and_set_cmd_args(int, char**);
	string get_input_file_name();

	//~cmd_args() {}
};