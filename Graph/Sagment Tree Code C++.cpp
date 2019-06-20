#include<bits/stdc++.h>
using namespace std;
int input[]={0,1,2,3,4,5,6,7};
int c=0;
int getSegSize(int inputSize)
{
    int segSize = (int)ceil(log2(inputSize));
    segSize = pow(2,segSize)*2 - 1;
    return segSize;
}
void build(int low,int high,int pos,int *segmentTree)
{
    if(low==high)
    {
        segmentTree[pos]=input[low];
        return;
    }
    int mid=(low+high)/2;
    build(low,mid,2*pos+1,segmentTree);
    build(mid+1,high,2*pos+2,segmentTree);
    segmentTree[pos]=min(segmentTree[2*pos+1],segmentTree[2*pos+2]);
}
void buildSum(int low,int high,int pos,int *segmentTree)
{
    if(low==high)
    {
        segmentTree[pos]=input[low];
        return;
    }
    int mid=(low+high)/2;
    buildSum(low,mid,2*pos+1,segmentTree);
    buildSum(mid+1,high,2*pos+2,segmentTree);
    segmentTree[pos]=(segmentTree[2*pos+1]+segmentTree[2*pos+2]);
}

int rangeMinQuery(int *segTree,int qlow,int qhigh,int low,int high,int pos)
{
    c++;
    if(qlow<=low && qhigh>=high)
        return segTree[pos];
    else if(qlow>high || qhigh<low)
        return INT_MAX;
    else{
        int mid = (low+high)/2;
        int q1=rangeMinQuery(segTree,qlow,qhigh,low,mid,2*pos+1);
        int q2=rangeMinQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2);
        return min(q1,q2);
    }
}

int rangeMinQuerySum(int *segTree,int qlow,int qhigh,int low,int high,int pos)
{
    c++;
    if(qlow<=low && qhigh>=high) //total overlap
        return segTree[pos];
    else if(qlow>high || qhigh<low) //no overlap
        return 0;
    else{                            //partial overlap
        int mid = (low+high)/2;
        int q1=rangeMinQuerySum(segTree,qlow,qhigh,low,mid,2*pos+1);
        int q2=rangeMinQuerySum(segTree,qlow,qhigh,mid+1,high,2*pos+2);
        return q1+q2;
    }
}

/* A recursive function to update the nodes which have the given
   index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is
             in input array.
   diff --> Value to be added to all nodes which have i in range */
int getMid(int s, int e) {  return s + (e -s)/2;  }

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    printf("start: %d, end: %d, index: %d, diff: %d, pos: %d\n",ss,se,i,diff,si);
    if (i < ss || i > se)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}



// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }

    // Get the difference between new value and old value
    int diff = new_val - arr[i];

    // Update the value in array
    //arr[i] = new_val;

    // Update the values of nodes in segment tree
    cout << endl << "updateValueUtil(st, 0, n-1, i, diff, 0) "<< endl;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}


int main()
{
    int *segmentTree=new int[getSegSize(sizeof(input)/sizeof(input[0]))];
    int *segmentTreeSum=new int[getSegSize(sizeof(input)/sizeof(input[0]))];
    build(0,7,0,segmentTree);
    buildSum(0,7,0,segmentTreeSum);

    for(int i=0;i<8;i++)
        cout<<input[i]<<" ";
    cout<<endl<<"Minimum "<<rangeMinQuery(segmentTree,0,3,0,7,0)<<endl;
    cout<<endl<<"Even Sum = "<<rangeMinQuerySum(segmentTreeSum,0,3,0,7,0)<<endl;
    //cout<<"Total count "<<c<<endl;
    updateValue(input,segmentTree,sizeof(input)/sizeof(input[0]),7,20);
    cout<<endl<<"Minimum "<<rangeMinQuery(segmentTree,0,7,0,7,0)<<endl;

}

