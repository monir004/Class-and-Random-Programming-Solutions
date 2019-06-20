#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int u,v,w;
}arr[20];
int n;
int root[100];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int findSet(int x)
{
    if(root[x]==x)
        return x;
    else return root[x]=findSet(root[x]);
}
void K()
{
    sort(arr,arr+n,cmp);
    int cost=0;
    for(int i=0;i<n;i++)
    {
        int u=arr[i].u;
        int v=arr[i].v;
        int w=arr[i].w;
        if(findSet(u)!=findSet(v))
        {
            root[root[u]]=root[v];
            cout<<u<<"\t"<<v<<endl;
            cost+=w;
        }
    }
    cout<<"Cost = "<<cost<<endl;
}
int main()
{
    cin>>n>>n;
    for(int i=0;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        arr[i].u=u;
        arr[i].v=v;
        arr[i].w=w;
        root[v]=v;
        root[u]=u;
    }
    K();
}
-/*
-...Input.....
-	9 13   (9 vertices and 13 edges)
	7 6 1
	8 2 2
	6 5 2
	0 1 4
	2 5 4
	8 6 4
	2 3 7
	7 8 7
	0 7 8
	1 2 8
	3 4 9
	1 7 11
	3 5 14

-	Total cost is = 37
-	output is :
-	7 = > 6
-	8 = > 2
-	6 = > 5
-	0 = > 1
-	2 = > 5
-	2 = > 3
-	0 = > 7
-	3 = > 4
-	Total 8 edges....
-*/
