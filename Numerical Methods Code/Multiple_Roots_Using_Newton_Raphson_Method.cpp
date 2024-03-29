#include<iostream>
#include<cmath>
using namespace std;
void deflat(int n, float a[11], float xr);
void newton(int n, float a[11], float xo, float *xr);
int main()
{
	int n, status, i, j;
	float a[11], root[10], xo, xr;
	cout << "Enter the degree of polynomial" << endl;
	cin >> n;
	cout << endl<<"Input poly coofficients ,a(1) to a("<<n+1<<")" << endl;
	for (i = 1; i <= n + 1; i++)
	{
		float value; cin >> value; a[i] = value;
	}
	cout << "Input initial guess" << endl;
	cin >> xo;
	for (i = n; i >= 2; i--)  //We're performing n-1 deflations
	{
		newton(n, a, xo, &xr);
		root[i] = xr;   // Storing the roots of polynomial
		deflat(n, a, xr);  // Deflate the polynomial by division (x-xr)
		xo = xr;    // Initial guess for next root
	}
	root[1] = -a[1] / a[2];         //computing the last root

	cout << "Roots of polynomial are" << endl;
	for (i = 1; i <= n; ++i)
		cout << "Root " << i << " = " << root[i] << endl;

	//system("pause");
}
//
void newton(int n, float a[11], float xo, float *xr)
{
	while (true)
	{
		float fx = a[n + 1];
		for (int i = n; i >= 1; --i)
		{
			fx = fx * xo + a[i];  // ((((a4*x)+a3)*x+a2)*x)+a1)*x)+a0
		}

		//computing the value of derrivatives of polynomial
		float fdx = a[n + 1] * n;
		for (int i = n; i >= 2; --i)
		{
			fdx = fdx*xo + a[i] * (i - 1);
		}

		*xr = xo - fx / fdx;   //computing a root
		if (fabs((*xr - xo) / (*xr)) <= .001) //Error check
		{
			return;
		}
		xo = *xr;

	}  //end of while loop
}

void deflat(int n, float a[11], float xr)
{
	float b[11]; int i;
	b[n + 1] = 0;
	//Evaluating the co-efficients of the reduced polynomial
	for (i = n; i >= 1; i--)
	{
		b[i] = a[i + 1] + xr*b[i + 1];
	}
	//change coefficients from b array to a array
	for (i = 1; i <= n + 1; i++)
	{
		a[i] = b[i];
	}
}
