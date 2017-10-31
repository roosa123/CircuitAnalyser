#pragma once
#include<string>

using namespace std;

class element {
	char type;
	string name;
	double value;
	int node_plus;
	int node_minus;
	bool data_correct;

public:
	element();
	element(const element&);

	void set_type(char);
	void set_name(string);
	void set_value(double);
	void set_node_plus(int);
	void set_node_minus(int);
	void set_if_data_incorrect();

	char get_type();
	string get_name();
	double get_value();
	int get_node_plus();
	int get_node_minus();
	bool get_data_control();

	~element() {}
};