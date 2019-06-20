#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(vector<int>*v, bool *visited,int s,stack<int>&st)
{
	cout << s << " ";
	visited[s] = true;
	vector<int>::iterator i;
	for (i = v[s].begin(); i != v[s].end(); ++i)
	{
		if (!visited[*i])
			dfs(v, visited, *i,st);
	}
	st.push(s);
}

int main()
{
	cout << "Enter total number of vertices and edges" << endl;
	int vertice, edge; cin >> vertice >> edge;
	vector<int>*V = new vector<int>[vertice];
	for (int i = 0; i < edge; i++)
	{
		int x, y; cin >> x >> y;
		V[x].push_back(y);
	}
	cout << "Enter the starting vertice" << endl;
	bool *visited = new bool[vertice];
	for (int i = 0; i < vertice; i++) visited[i] = false;
	int s; cin >> s;
	stack<int>st;
	dfs(V, visited, s,st);
	for (int i = 0; i < vertice; i++)
		if (!visited[i]) dfs(V, visited, i,st);
	cout << endl;
	cout << "Topological sort" << endl;
	while (!st.empty())
	{
		cout << st.top() << " "; st.pop();
	}
	cout << endl;
	//system("pause");
}
