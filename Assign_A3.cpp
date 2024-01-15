#include <iostream>
using namespace std;
#define INF 9999999
class Graph
{
    int v;
    int **Matrix;

public:
    void createGraph()
    {
        cout << "Enter the number of vertices" << endl;
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
                cout << "Enter the cost between" << i << " and " << j << endl;
                cin >> Matrix[i][j];
            }
        }
    }

    void displayGraph()
    {
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
        int no_edges = 0;
        int selected[v + 1] = {0};
        selected[1] = true;
        int x; //  row number
        int y; //  col number
        int sum = 0;
        // print for edge and weight
        cout << "Edge"
             << " : "
             << "Weight";
        cout << endl;
        while (no_edges < v - 1)
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
                        { // not in selected and there is an edge
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
            cout << x << " - " << y << " :  " << Matrix[x][y];
            cout << endl;
            selected[y] = true;
            no_edges++;
            sum = sum + Matrix[x][y];
        }
        cout << "MINIMUM COST OF SPANNING TREE : " << sum << endl;
    }
};
int main()
{
    Graph g;
    g.createGraph();
    g.displayGraph();
    g.prims();
}
/*EXAMPLE-1

// Enter the number of vertices
// 5
// Enter the cost between1 and 1
// 0
// Enter the cost between1 and 2
// 2
// Enter the cost between1 and 3
// 0
// Enter the cost between1 and 4
// 0
// Enter the cost between1 and 5
// 5
// Enter the cost between2 and 1
// 2
// Enter the cost between2 and 2
// 0
// Enter the cost between2 and 3
// 3
// Enter the cost between2 and 4
// 0
// Enter the cost between2 and 5
// 0
// Enter the cost between3 and 1
// 0
// Enter the cost between3 and 2
// 3
// Enter the cost between3 and 3
// 0
// Enter the cost between3 and 4
// 4
// Enter the cost between3 and 5
// 1
// Enter the cost between4 and 1
// 0
// Enter the cost between4 and 2
// 0
// Enter the cost between4 and 3
// 4
// Enter the cost between4 and 4
// 0
// Enter the cost between4 and 5
// 11
// Enter the cost between5 and 1
// 5
// Enter the cost between5 and 2
// 0
// Enter the cost between5 and 3
// 1
// Enter the cost between5 and 4
// 11
// Enter the cost between5 and 5
// 0
// 0 2 0 0 5
// 2 0 3 0 0
// 0 3 0 4 1
// 0 0 4 0 11
// 5 0 1 11 0
// Edge : Weight
// 1 - 2 :  2
// 2 - 3 :  3
// 3 - 5 :  1
// 3 - 4 :  4
// MINIMUM COST OF SPANNING TREE : 10
*/

// EXAMPLE-2
/*
Enter the number of vertices
5
Enter the cost between1 and 1
0
Enter the cost between1 and 2
10
Enter the cost between1 and 3
0
Enter the cost between1 and 4
4
Enter the cost between1 and 5
0
Enter the cost between2 and 1
10
Enter the cost between2 and 2
0
Enter the cost between2 and 3
3
Enter the cost between2 and 4
2
Enter the cost between2 and 5
6
Enter the cost between3 and 1
0
Enter the cost between3 and 2
3
Enter the cost between3 and 3
0
Enter the cost between3 and 4
0
Enter the cost between3 and 5
0
Enter the cost between4 and 1
4
Enter the cost between4 and 2
2
Enter the cost between4 and 3
0
Enter the cost between4 and 4
0
Enter the cost between4 and 5
1
Enter the cost between5 and 1
0
Enter the cost between5 and 2
6
Enter the cost between5 and 3
0
Enter the cost between5 and 4
1
Enter the cost between5 and 5
0
0 10 0 4 0
10 0 3 2 6
0 3 0 0 0
4 2 0 0 1
0 6 0 1 0
Edge : Weight
1 - 4 :  4
4 - 5 :  1
4 - 2 :  2
2 - 3 :  3
MINIMUM COST OF SPANNING TREE : 10
*/