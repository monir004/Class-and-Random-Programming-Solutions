#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter total process ";
    int process;
    cin>>process;
    int arr[process];
    for(int i=0; i<process; i++)
    {
        int num;
        cin>>num;
        arr[i]=num;
    }
    cout<<"Enter slice size "<<endl;
    int slice;
    cin>>slice;
    int total=0;
    int i=-1;
    while(true)
    {
        i++;
        if(i==process)
        {
            i=0;
        }
        //check if all the array elements is zero or not
        int j=process;
        while(--j>=0 && arr[j]==0);
        if(j<0) break;


        if(arr[i]==0) continue;
        if(arr[i]>slice)
        {
            cout<<"Process name "<<i+1;
            cout<<"    Remaining time "<<arr[i]-slice;
            cout<<"    Total time "<<total+slice<<endl;
            arr[i]=arr[i]-slice;
            total=total+slice;
        }
        else
        {
            cout<<"Process name "<<i+1;
            cout<<"    Remaining time "<<0;
            cout<<"    Total time "<<total+arr[i]<<endl;
            total=total+arr[i];
            arr[i]=0;
        }
    }

}
