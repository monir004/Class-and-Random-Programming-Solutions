
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int vertice, edge;
vector<int>*adj = new vector<int>[100];
bool *visited = new bool[100];
stack<int>st;
void topo(int s)
{
	visited[s] = true;
	vector<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); i++)
	{
		if (!visited[*i])
			topo(*i);
	}
	st.push(s);
}
int main()
{
	cout << "Enter the number of vertices and edges" << endl;
	cin >> vertice >> edge;
	cout << "Enter edge" << endl;
	for (int i = 0; i < edge; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	for (int i = 1; i <= vertice; i++)
		visited[i] = false;
	for (int i = 1; i <= vertice; i++)
	{
		if (!visited[i])   //if not visited
			topo(i);
	}
	while (st.size())
	{
		cout << st.top() << " ";
		st.pop();
	}
}
