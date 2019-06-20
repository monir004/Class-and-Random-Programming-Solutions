#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>ipair;
vector<ipair>*adj=new vector<ipair>[100];
vector<int>parent(100,-1);
vector<int>dist(100,9999);
int vertice,edge;
void Prims(int source)
{
    priority_queue<ipair,vector<ipair>,greater<ipair> >pq;
    pq.push(ipair(0,source));
    vector<bool>inMST(100,false);
    while(pq.size()>0)
    {
        int u=pq.top().second;
        inMST[u]=true; //inMST[u]=true
        pq.pop();
        vector<ipair>::iterator i;
        for(i=adj[u].begin(); i!=adj[u].end(); i++)
        {
            int v=i->first;
            int w=i->second;
            if(dist[v]>w && inMST[v]==false) //inMST[v]==false
            {
                dist[v]=w;
                parent[v]=u;
                pq.push(ipair(dist[v],v));
            }
        }
    }
    for(int i=1; i<vertice; i++)
    {
        cout<<parent[i]<<" = > "<<i<<endl;
    }
}


int main()
{
    cout<<"Enter vertice and edge "<<endl;
    cin>>vertice>>edge;
    for(int i=0; i<edge; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back(ipair(y,w));
        adj[y].push_back(ipair(x,w));
    }
    cout<<"Enter source "<<endl;
    int source;
    cin>>source;
    Prims(source);
}
/*
Input
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

output....
0 = > 1
1 = > 2
2 = > 3
3 = > 4
2 = > 5
5 = > 6
6 = > 7
2 = > 8

*/
