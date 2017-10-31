#pragma once

class complex {
	double re;
	double im;

public:
	complex();
	complex(double);
	complex(double, double);

	double get_re();
	double get_im();

	void set_re(double);
	void set_im(double);

	complex operator+(complex&);
	complex& operator=(complex&);
	complex& operator+=(complex&);
	complex operator*(complex&);
	complex operator-(complex&);
	complex operator/(complex&);
};