#include<stdio.h>
#include<iostream>
using namespace std;

void main()
{
    int x[10], y[10], p[10];
    int k, f, n, j = 1, f1, f2 = 0;
    cout << "Enter the number of observations" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "ENter the value of x[" << i << "] = ";
        int a;
        cin >> a;
        x[i] = a;
        cout << "Enter the value of y[" << i << "] = ";
        int b;
        cin >> b;
        y[i] = b;
    }

    f = y[0];
    cout << "Enter the value of x ";
    cin >> k;

    while(n!=1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            y[i] = ((y[i] - y[i+1]) / (x[i] - x[i+j]));
            cout << y[i] << "   ";

        }
        cout << endl;
        f1 = 1;
        for (int i = 0; i < j; i++)
        {
            f1 *= (k - x[i]);
        }
        f2 += (y[0] * f1);
        n--;
        j++;
    }
    f += f2;
    printf("\nf(%d) = %d\n\n\n", k, f);
}
