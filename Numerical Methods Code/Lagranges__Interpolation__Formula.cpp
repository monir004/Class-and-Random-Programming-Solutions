#include<iostream>
using namespace std;
int main()
{
	double x[100], y[100], a, n;
	cout << "Enter the number of terms on the table " << endl;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "Enter the value of x[" << i << "] = ";
		int a; cin >> a;
		x[i] = a;
		cout << "Enter the value of y[" << i << "] = ";
		int b; cin >> b;
		y[i] = b;
	}
	cout << "Enter the value of x to find the respective value of y" << endl;
	cin >> a;

	double res = 0;
	for (int i = 0; i<n; i++)
	{
		double t = 1;
		double s = 1;
		for (int j = 0; j<n; j++)
		{
			if (i!=j)
			{
				t = t*(x[i] - x[j]);
				s = s*(a - x[j]);
			}
		}
		res=res + ((s / t)*y[i]);
	}
	cout << "Result is "<<res << endl;
}
