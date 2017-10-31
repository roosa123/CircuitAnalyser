#include<cmath>
#include"parser.h"
#include"element.h"

using namespace std;

parser::parser() :read_element(), line("") {}

void parser::set_line(string line_to_set) {
	line = line_to_set;
}

void parser::parse_line() {
	int position_of_new_substring = 0;

	string delimiter(" ");
	string integer_digits("0123456789");
	string signed_integer_digits("-0123456789");
	string float_digits("-0123456789.");

	read_element.set_type(line.at(0));

	int name_value_nodes = 4;
	size_t is_digit;
	bool incorrect_data = false;
	char scientific = 'e';	// "e" - scientific notation

	for (int i = 0; i < name_value_nodes; ++i) {
		position_of_new_substring = line.find(delimiter);

		switch (i) {
		case 0:	// saving element's name
			read_element.set_name(line.substr(0, position_of_new_substring));
			break;

		case 1: // saving name of node+
			read_element.set_node_plus(stoi(line.substr(0, position_of_new_substring)));
			break;

		case 2: // saving name of node-
			read_element.set_node_minus(stoi(line.substr(0, position_of_new_substring)));
			break;

		case 3: // reading element's value
			is_digit = line.find_first_not_of(float_digits);

			if (is_digit != string::npos) // Checking, if there are more letters in the 'line'. If so, then...
				if (line.at(is_digit) == scientific) { // isn't it scientific notation
					double value_tmp = stod(line.substr(0, is_digit)); // save mantisa

					position_of_new_substring = line.find(delimiter); // are there any spaces (if so, characters after them will be ignored)

					if (position_of_new_substring != string::npos) // are there any spaces? If so, delete everything after them
						line.erase(position_of_new_substring/*, line.size() - position_of_new_substring - 1*/);
					
					if (line.find_first_not_of(signed_integer_digits, is_digit + 1) != string::npos) { // is it integer?
						incorrect_data = true;
						break;
					}

					value_tmp *= pow(10, stod(line.substr(is_digit + 1, line.size() - 1))); // everything's OK, we can raise to given power and save in an element

					read_element.set_value(value_tmp);
					break;
				}
				else { // there are non significant letters - data error
					incorrect_data = true;
					break;
				}
			else // there are no letters - no scietific notation, value in basic units
				read_element.set_value(stod(line.substr(0, line.size() - 1)));
			break;

		default:
			break;
		}
		
		if (incorrect_data)
			break;

		line.erase(0, position_of_new_substring + delimiter.length());
	}

	if (incorrect_data)
		read_element.set_if_data_incorrect();
}

element* parser::get_element() {
	return &read_element;
}