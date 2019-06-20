#include<iostream>
#include<algorithm> //no arrival time.
using namespace std;
struct SJF{
    string name;
    int burst_time;
}arr[20];
bool comparison(SJF a, SJF b)
{
    return a.burst_time < b.burst_time;
}
int main()
{
    int total_waiting_time=0,total_burst_time=0;
    cout<<"Enter number of process ";
    int process;cin>>process;
    for(int i=0;i<process;i++)
    {
        cout<<"Enter Process name Burst time => ";

        string p_name;cin>>p_name;
        arr[i].name=p_name;
        int b_time;cin>>b_time;
        total_burst_time+=b_time;
        arr[i].burst_time=b_time;
    }
    sort(arr,arr+process,comparison);
    int waiting[10];
    waiting[0]=0;
    for(int i=0;i<(process-1);i++)
    {
        int total=0;
        for(int j=0;j<=i;j++)
        {
            total+=arr[j].burst_time;
        }
        waiting[i+1]=total;
        total_waiting_time+=waiting[i+1];
    }
    cout<<"Process - waiting time - burst time"<<endl;
    for(int i=0;i<process;i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<waiting[i]<<"\t\t"<<arr[i].burst_time<<endl;
    }
    cout<<"Total waiting time "<<total_waiting_time<<endl;
    cout<<"Total burst time "<<total_burst_time<<endl;
}
