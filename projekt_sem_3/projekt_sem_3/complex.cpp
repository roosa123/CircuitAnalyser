#include"complex.h"

complex::complex() :im(0), re(0) {}

complex::complex(double real_or_imaginary) :re(real_or_imaginary), im(real_or_imaginary) {}

complex::complex(double real, double imaginary) :re(real), im(imaginary) {}

double complex::get_re() {
	return re;
}

double complex::get_im() {
	return im;
}

void complex::set_re(double real) {
	re = real;
}
void complex::set_im(double imaginary) {
	im = imaginary;
}

complex complex::operator+(complex& add_me) {
	complex result = *this;

	result.re += add_me.re;
	result.im += add_me.im;

	return result;
}

complex& complex::operator=(complex& complex_to_ascribe) {
	re = complex_to_ascribe.re;
	im = complex_to_ascribe.im;

	return *this;
}

complex& complex::operator+=(complex& add_me) {
	re += add_me.re;
	im += add_me.im;

	return *this;
}

complex complex::operator*(complex& multiply_me) {
	complex result = *this;

	double re_tmp = result.get_re();
	double im_tmp = result.get_im();

	result.set_re(re_tmp * multiply_me.get_re() - im_tmp * multiply_me.get_im());
	result.set_im(re_tmp * multiply_me.get_im() + im_tmp * multiply_me.get_re());

	return result;
}

complex complex::operator-(complex& subtract_me) {
	complex result = *this;

	result.re -= subtract_me.re;
	result.im -= subtract_me.im;

	return result;
}

complex complex::operator/(complex& divide_by_me) {
	complex result = *this;

	double re_tmp = result.re;
	double im_tmp = result.im;

	result.re = (re_tmp * divide_by_me.get_re() + im_tmp * divide_by_me.get_im()) / (divide_by_me.get_re() * divide_by_me.get_re() + divide_by_me.get_im() * divide_by_me.get_im());

	result.im = (im_tmp * divide_by_me.get_re() - re_tmp * divide_by_me.get_im()) / (divide_by_me.get_re() * divide_by_me.get_re() + divide_by_me.get_im() * divide_by_me.get_im());

	return result;
}