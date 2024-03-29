#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double low = -0.5, high = 1000.0; //lower limit and upper limit
double dx = 0.01;         //Incremental value
double x;
int n;
double h(double *arr,double x)    //Horners method
{
	double res = arr[n];
	for (int i = n-1; i >=0; --i)
	{
		res = res*x + arr[i];  // ((((a4*x)+a3)*x+a2)*x)+a1)*x)+a0
	}
	return res;
}
double x1,x2;
//   Equation f(x) = x^3-6X^2+5X+0   and roots are 0,1,5 and so on...
int main()
{
    cout<<"Enter the degree "<<endl;
    cin>>n;
	double arr[n+1];
	cout<<"Enter the co-efiicients"<<endl;
	for(int i=0;i<n+1;++i)
    {
        int v;cin>>v;
        arr[i]=v;
    }
	while (true)
	{
		x1 = low, x2 = low + dx;                      ////works like step 3
		double f1 = h(arr,x1);
		double f2 = h(arr, x2);
		if (f1*f2 < 0)
		{
			while (true)
			{
				double xo = (x1 + x2) / 2;
				double fo = h(arr, xo);
				if (f1*fo < 0) { x2 = xo; f2 = fo; }
				else { x1 = xo; f1 = fo; }
				if (fabs((x2 - x1) / x2) < .001)
				{
					double root = (x1 + x2) / 2;
					cout << fixed << setprecision(3) << root << endl;
					break;
				}
			}
		}
		if (x2 < high)
		{
			low = x2;
		}
		else break;
	}

	//system("pause");
	return 0;
}
