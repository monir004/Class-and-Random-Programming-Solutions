#include<iostream>
	#include<vector>
	#include<queue>
	#include<cstring>
	#define MAX 100
	using namespace std;
	int x[] = { 2,2,-2,-2,1,1,-1,-1 };
	int y[] = { 1,-1,1,-1,2,-2,2,-2 };
	int row, col, trees, startX, startY, desX, desY, i, j;
	#define BOUNDARY(i,j) ((i>=0 && i<row)&&(j>=0 && j<col)) //Boundary check of the grid
	#define FOR(i,n) for(int i=0;i<n;i++) //For loop from i to n-1
	int grid[MAX][MAX];
	bool visited[MAX][MAX];
	pair<int, int>parent[MAX][MAX];
	void dfs_path_print(int dX, int dY);
	void bfs()
	{
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int> >q;
		q.push(make_pair(startX, startY));
		visited[startX][startY] = 1;
		while (!q.empty())
		{
			pair<int, int>p;
			p = q.front();
			//cout << p.first << "   " << p.second << endl;
			FOR(i, 8)
			{
				int nx = p.first+x[i];
				int ny = p.second+y[i];
				if (BOUNDARY(nx , ny ) && !grid[nx][ny] && !visited[nx][ny])
				{
					visited[nx][ny] = 1;
					parent[nx][ny].first = p.first;
					parent[nx][ny].second = p.second;
					q.push(make_pair(nx, ny));
				}
			}
			q.pop();

		}


	}
	void dfs_path_print(int dX,int dY)
	{
		static int count = 0;
		if (startX == dX && startY == dY)
		{
			cout << "Yes - Knight can reach home in " << count << " steps.";
			cout << endl << "The path is: " << endl;
			cout << startX << "    " << startY << endl;
		}
		else if (parent[dX][dY].first == 0 && parent[dX][dY].second == 0 && !count) //!count in case case of source 0 0
		{
			cout << "No - Knight can't reach home" << endl;
		}
		else {
			count++;
			dfs_path_print(parent[dX][dY].first, parent[dX][dY].second);
			cout << dX << "    " << dY << endl;
		}
	}
	int main()
	{
		//freopen("in.txt", "r", stdin);
		cout << "Enter the Dimension of the Grid: ";
		cin >> row >> col;
		cout << "Enter the number of trees: ";
		cin >> trees;
		memset(grid, 0, sizeof(grid));
		cout << "Enter position in trees:" << endl;
		FOR(i, trees)
		{
			int x, y; cin >> x >> y;
			grid[x][y] = 1;
		}
		cout << "Enter Knight's Position: ";
		cin >> startX >> startY;
		cout << "Enter Home Position: ";
		cin >> desX >> desY;
		bfs();
		dfs_path_print(desX, desY);
		//system("pause");
	}
