#include<iostream>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
typedef pair<int, int>ipair;
vector<ipair>*adj = new vector<ipair>[100];
vector<int>dist(100, 9999);
int vertice, edge;
vector<int>parent(100);

void path(int s, int e)
{
	if (s == e) {

	}
	else path(s, parent[e]);
	cout << e << "  ";
}
void dijkstra(int start, int end)
{

	priority_queue<ipair, vector<ipair>, greater<ipair> >pq;
	dist[start] = 0;
	pq.push(ipair(0, start));
	while (pq.size() > 0)
	{
		int u = pq.top().second;
		pq.pop();
		vector<ipair>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); i++)
		{
			int v = i->first;
			int w = i->second;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.push(ipair(dist[v], v));
			}
		}
	}
	cout << "Distance f" << endl;
	for (int i = 0; i < vertice; i++)
	{
		cout << i << "   " << dist[i] << endl;
	}
	path(start, end);
}
int main()
{
	cout << "Enter vertices and edges" << endl;
	cin >> vertice >> edge;
	cout << "Enter edges" << endl;
	for (int i = 0; i < edge; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back(ipair(y, w));
		adj[y].push_back(ipair(x, w));
	}
	cout << "Enter source and end vertice" << endl;
	int start, end; cin >> start >> end;
	dijkstra(start, end);
//	system("pause");
}
