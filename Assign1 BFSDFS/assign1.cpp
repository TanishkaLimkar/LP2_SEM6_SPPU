#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
    unordered_map<int, list<int>> adjlist;

    void addEdge(int u, int v, bool direction)
    {
        adjlist[u].push_back(v);

        if (direction == 0)
        {
            adjlist[v].push_back(u);
        }
    }

    void printEdge()
    {
        for (auto node : adjlist)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << " , ";
            }
            cout << endl;
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << " ";
        visited[src] = true;
        for (auto node : adjlist[src])
        {
            if (!visited[node])
            {
                dfs(node, visited);
            }
        }
    }

    void dfs_levelwise(int src, unordered_map<int, bool> &visited, unordered_map<int, int> &level, int currlevel)
    {
        cout << "Node" << src << " -> " << "level" << currlevel << endl;
        visited[src] = true;
        level[src] = currlevel;

        for (auto node : adjlist[src])
        {
            if (!visited[node])
            {
                dfs_levelwise(node, visited, level, currlevel + 1);
            }
        }
    }
    void bfs_sample(queue<int> &q, unordered_map<int, bool> &visited, unordered_map<int, int> &level)
    {
        if (q.empty())
        {
            return;
        }
        int frontnode = q.front();
        q.pop();
        cout << frontnode << " ";

        for (auto node : adjlist[frontnode])
        {
            if (!visited[node])
            {
                q.push(node);
                visited[node] = true;
                level[node] = level[frontnode] + 1;
            }
        }
        bfs_sample(q, visited, level);
    }
    void bfs(int src, unordered_map<int, int> &level)
    {
        queue<int> q;
        q.push(src);
        unordered_map<int, bool> visited;
        visited[src] = true;
        level[src] = 0;
        bfs_sample(q, visited, level);
    }
};

int main()
{
    Graph g;

    cout << "Enter the number of vertices and edges " << endl;
    int vertices, edges;
    cin >> vertices >> edges;

    cout << "Enter the values of (u ,v) to addEdge" << endl;
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g.addEdge(u, v, false);
    }

    unordered_map<int, bool> visited1;
    unordered_map<int, bool> visited2;
    unordered_map<int, int> level;

    cout << "Enter the startNode : " << endl;
    int start;
    cin >> start;

    cout << "DFS : " << endl;
    g.dfs(start, visited1);
    cout << endl;

    cout << "DFS LEVELWISE : " << endl;
    g.dfs_levelwise(start, visited2, level, 0);
    cout << endl;

    cout << "BFS : " << endl;
    g.bfs(start, level);
    cout << endl;

    cout << "BFS LEVELWISE : " << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << "Node" << i << " -> " << "level" << level[i] << endl;
    }

    return 0;
}

/*

Enter the number of vertices and edges
8 7
Enter the values of (u ,v) to addEdge
0 1
0 2
0 3
1 4
1 5
2 6
3 7
Enter the startNode :
0
DFS :
0 1 4 5 2 6 3 7
DFS LEVELWISE :
Node0 -> level0
Node1 -> level1
Node4 -> level2
Node5 -> level2
Node2 -> level1
Node6 -> level2
Node3 -> level1
Node7 -> level2

BFS :
0 1 2 3 4 5 6 7
BFS LEVELWISE :
Node1 -> level0
Node2 -> level1
Node3 -> level1
Node4 -> level1
Node5 -> level2
Node6 -> level2
Node7 -> level2
Node8 -> level2
*/