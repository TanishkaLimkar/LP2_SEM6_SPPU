#include <bits/stdc++.h>
using namespace std;
#define INF 9999999

class Graph
{

    int v;
    int **Matrix;

public:
    void createGraph()
    {
        cout << "Enter the number of cities" << endl;
        cin >> v;

        Matrix = new int *[v];

        for (int i = 1; i <= v; i++)
        {
            Matrix[i] = new int[v];
        }

        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                cout << "Enter the distance between city" << i << " & city" << j << endl;
                cin >> Matrix[i][j];
            }
        }
    }

    void print()
    {
        cout << "Displaying the Map between cities : " << endl;
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims()
    {
        int no_Edges = 0;
        int selected[v + 1] = {0};
        selected[1] = true;
        int x;
        int y;
        int sum = 0;

        while (no_Edges < v - 1)
        {
            int min = INF;
            x = 0;
            y = 0;

            for (int i = 1; i <= v; i++)
            {
                if (selected[i])
                {
                    for (int j = 1; j <= v; j++)
                    {
                        if (!selected[j] && Matrix[i][j])
                        {
                            if (min > Matrix[i][j])
                            {
                                min = Matrix[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            cout << "city" << x << " -> " << "city" << y << " : " << Matrix[x][y] << endl;
            selected[y] = true;
            no_Edges++;
            sum += Matrix[x][y];
        }
        cout << "THE COST OF MINIMUM SPANNING TREE : " << sum << endl;
    }
};
int main()
{
    Graph g;
    g.createGraph();
    g.print();
    g.prims();

    return 0;
}

// 0 2 0 0 5
// 2 0 3 0 0
// 0 3 0 4 1
// 0 0 4 0 11
// 5 0 1 11 0