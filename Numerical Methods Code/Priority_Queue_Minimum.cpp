#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int>pq;
    for(int i=5;i>=1;--i)
    {
        cout<<"Enter a number   ";int num;cin>>num;
        pq.push(num*-1); // Pushing the negative value and it will push large value in the last
        //and small value in the first.. and thus we can pop up minimum value first...
        //It's a good idea to code on
    }
    cout<< pq.top()*-1<<endl;  // and here we are the negative value... because the
    //smallest value is pushed on in negative way.. So we have to multiply it by -1 to take the original value...

}
