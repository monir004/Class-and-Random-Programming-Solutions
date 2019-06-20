#include<bits/stdc++.h>
using namespace std;

int n;
double h(double x,double *arr)
{
    double result=arr[0];
    for(int i=1; i<n; i++)
    {
        result = result*x+arr[i];
    }

    return result;
}

int main()
{
    cout<<"Enter the height degree of polynomial"<<endl;
    cin>>n;
    n++;
    double arr[n];
    cout<<"Enter the coordinates"<<endl;
    for(int i =0; i<n; i++)
    {
        double num;
        cin>>num;
        arr[i] = num;
    }
    cout<<"Enter the two initial gusses"<<endl;
    double x1,x2;
    cin>>x1>>x2;
    while(true)
    {
        double x3;
        x3 = ((h(x2,arr)*x1)-(h(x1,arr)*x2))/(h(x2,arr)-h(x1,arr));
        if((fabs((x3-x2)/x3)) >.001)
        {
            cout<<"x2 = "<<   x3 <<"  = "<<endl;
            x1=x2;
            x2=x3;
        }
        else
        {
            printf("x3 = %.3lf",x3);
            break;
        }
    }
    return 0;
}
