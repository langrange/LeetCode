#include <cmath>
#include <iostream>
using namespace std;

double reverse_AD(const double x[2], double y_ad[1], double x_ad[2]) {
	double c = x[0] * x[1];
	double d = c + x[1];
	double y = d;

	/* Adjoint part: */
	// init
	double d_ad = 0, c_ad = 0;

	d_ad = y_ad[0]; // 1

	c_ad = c_ad + d_ad;   // 2
	x_ad[1] = x_ad[1] + d_ad;
	d_ad = 0;

	x_ad[0] = x_ad[0] + x[1] * c_ad; // 3
	x_ad[1] = x_ad[1] + x[0] * c_ad;
	c_ad = c_ad;

	return y;
}

int main()
{
	double x[] = { 5.0, 2.0 };
	double y_ad[1] = { 1.0 };// init to 1
	double x_ad[2] = { 0, 0 };
	double y = reverse_AD(x, y_ad, x_ad);
	cout << "y=" << y << "\n";
	cout << "dy/dy=" << y_ad[0] << "\n";
	cout << "dy/dx0=" << x_ad[0] << "\n";
	cout << "dy/dx1=" << x_ad[1] << "\n";
	return 0;
}