#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];

        for (int i = 0; i < v; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {

        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s2] < rank[s1])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
    }

    void addEdge(int x, int y, int w)
    {
        edgeList.push_back({w, x, y});
    }

    void kruskal_mst()
    {
        sort(edgeList.begin(), edgeList.end());
        DSU s(v);
        int ans = 0;

        cout << "Following shows the distance between cities : " << endl;
        for (auto edge : edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;

                cout << "city" << x << " -> " << "city" << y << " : " << w << endl;
            }
        }

        cout << "The minimum cost of spanning tree is : " << ans << endl;
    }
};
int main()
{
    cout << "Enter the number of cities : " << endl;
    int v;
    cin >> v;
    cout << "Enter the number of Edges between the cities : " << endl;
    int e;
    cin >> e;

    Graph g(v);
    cout << "Enter the Source destination ad weight" << endl;
    for (int i = 0; i < e; i++)
    {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        g.addEdge(source, destination, weight);
    }

    g.kruskal_mst();

    return 0;
}

/*
Enter the number of cities :
5
Enter the number of Edges between the cities :
7
Enter the Source destination ad weight
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
Following shows the distance between cities :
city0 -> city1 : 2
city1 -> city2 : 3
city1 -> city4 : 5
city0 -> city3 : 6
The minimum cost of spanning tree is : 16
*/