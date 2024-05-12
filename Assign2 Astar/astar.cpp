#include <bits/stdc++.h>
using namespace std;

class PuzzleState
{

public:
    vector<vector<int>> board;
    int heuristic;
    int moves;

    PuzzleState(vector<vector<int>> b, int h, int m)
    {
        board = b;
        heuristic = h;
        moves = m;
    }

    bool operator==(const PuzzleState &other) const
    {
        return board == other.board;
    }
};

class CompareHeuristic
{

public:
    bool operator()(const PuzzleState &a, const PuzzleState &b)
    {
        return a.heuristic > b.heuristic;
    }
};

int calculateManhattanDistance(vector<vector<int>> &current, vector<vector<int>> &goal)
{
    int distance = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int value = current[i][j];

            if (value != 0)
            {
                int goalrow = (value - 1) / 3;
                int goalcol = (value - 1) % 3;
                distance += abs(i - goalrow) + abs(j - goalcol);
            }
        }
    }

    return distance;
}

void print(vector<vector<int>> &state)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
}

void solvePuzzle(vector<vector<int>> &initial, vector<vector<int>> &goal)
{
    priority_queue<PuzzleState, vector<PuzzleState>, CompareHeuristic> pq;

    map<vector<vector<int>>, int> visited;

    int initialHeuristic = calculateManhattanDistance(initial, goal);

    PuzzleState initialstate(initial, initialHeuristic, 0);
    pq.push(initialstate);
    visited[initial] = initialHeuristic;

    while (!pq.empty())
    {
        PuzzleState current = pq.top();
        pq.pop();

        cout << "CURRENT STATE : " << endl;
        print(current.board);
        cout << "Heuristic Value : " << current.heuristic << endl;
        cout << "Moves : " << current.moves << endl;

        if (current.board == goal)
        {
            cout << "REACHED GOAL STATE" << endl;

            return;
        }

        int row, col;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (current.board[i][j] == 0)
                {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (auto dir : directions)
        {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
            {
                vector<vector<int>> newState = current.board;

                swap(newState[row][col], newState[newRow][newCol]);

                int newHeuristic = calculateManhattanDistance(newState, goal);
                PuzzleState nextState(newState, newHeuristic, current.moves + 1);

                if (visited.find(newState) == visited.end() || newHeuristic < visited[newState])
                {
                    visited[newState] = newHeuristic;
                    pq.push(nextState);
                }
            }
        }
    }
    cout << "No output found" << endl;
}

int main()
{
    vector<vector<int>> initial(3, vector<int>(3, 0));
    vector<vector<int>> goal(3, vector<int>(3, 0));

    cout << "Enter the elements of the initial state:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 3; ++j)
        {
            cin >> initial[i][j];
        }
    }

    cout << "Enter the elements of the goal state:" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 3; ++j)
        {
            cin >> goal[i][j];
        }
    }

    solvePuzzle(initial, goal);

    return 0;
}