#include <bits/stdc++.h>
using namespace std;
int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isValid(int x, int y, int N, int M)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}
int find_queen_min_stp(int N, int M, int Ki, int Kj, int Qi, int Qj)
{
    int minSteps[N][M];
    memset(minSteps, -1, sizeof(minSteps));

    queue<pair<pair<int, int>, int>> q;

    q.push({{Ki, Kj}, 0});
    minSteps[Ki][Kj] = 0;

    while (!q.empty())
    {
        int current_i = q.front().first.first;
        int current_j = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        if (current_i == Qi && current_j == Qj)
        {
            return steps;
        }

        for (int i = 0; i < 8; ++i)
        {
            int new_i = current_i + moves[i][0];
            int new_j = current_j + moves[i][1];

            if (isValid(new_i, new_j, N, M) && minSteps[new_i][new_j] == -1)
            {
                minSteps[new_i][new_j] = steps + 1;
                q.push({{new_i, new_j}, steps + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N, M, Ki, Kj, Qi, Qj;
        cin >> N >> M >> Ki >> Kj >> Qi >> Qj;

        int result = find_queen_min_stp(N, M, Ki, Kj, Qi, Qj);
        cout << result << endl;
    }

    return 0;
}