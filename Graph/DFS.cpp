#include<iostream>
#include<stack>
#include<list>
#include<cstring>
#include<vector>
using namespace std;
void DFS(int start,list<int>*V,bool *visited)
{
	visited[start] = true;
	cout << start << " ";
	list<int>::iterator i;
	for(i=V[start].begin();i!=V[start].end();++i)
	{
		if (!visited[*i])
		{
			DFS(*i, V, visited);
		}
	}
}
int main()
{
	cout << "Enter number of vertices and edges" << endl;
	int vertice, edge;
	cin >> vertice >> edge;
	list<int>*V = new list<int>[vertice];
	for (int i = 0; i < edge; i++)
	{
		int x, y; cin >> x >> y;
		V[x].push_back(y);
	}
	bool *visited = new bool[vertice];
	for (int i = 0; i < vertice; i++) visited[i] = false;

	DFS(0,V,visited);
	//system("pause");
}
