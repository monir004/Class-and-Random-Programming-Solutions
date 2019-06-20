#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
#define INF 1<<29
typedef pair<int, int>ipair;
list<ipair>*adj = new list<ipair>[1000];
int vertice, edge;
void shortestPath(int source)
{
	priority_queue<ipair, vector<ipair>, greater<ipair>>pq;
	vector<int>dist(vertice, INF);
	pq.push(make_pair(0, source));
	dist[source] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second; pq.pop();
		list<ipair>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int w = (*i).second;
			if (dist[v] > (dist[u] + w))
			{
				dist[v] = dist[u] + w;
				pq.push(ipair(dist[v], v));
			}
		}
	}
	cout << "Vertex distance from source" << endl;
	for (int i = 0; i < vertice; ++i)
	{
		cout << i << "      " << dist[i] << endl;
	}
}
int main()
{
	cout << "Enter number od vertices and edges" << endl; cin >> vertice >> edge;
	for (int i = 0; i < edge; ++i)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back(ipair(y, w));
		adj[y].push_back(ipair(x, w));
	}
	cout << "Enter a source" << endl; int source; cin >> source;
	shortestPath(source);
//	system("pause");
}
