#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
//f(x) = x^2 -3x +2
//f'(x) = 2x-3
double newton_raphson(double num)
{
	while (true) {
		double f1 = (num*num) - 3 * num + 2;
		double f2 = 2 * num - 3;

		double f = num - (f1 / f2);
		// << fixed << setprecision(3) << f << endl;
		if (fabs((f - num) / f) > .005)
			num = f;
		else break;
	}
	return num;
}

int main()
{
	cout << "Enter the initial guess" << endl;
	double num;
	cin >> num;
	cout << fixed << setprecision(3) << newton_raphson(num) << endl;

	//system("pause");
}
