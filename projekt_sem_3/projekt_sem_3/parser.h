#pragma once

#include<string>
#include"element.h"

using namespace std;

class parser {
	string line;
	element read_element;

public:
	parser();

	void set_line(string);
	void parse_line();
	element* get_element();

	~parser() {}
};