#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long int u, v, c;
    Edge(long long int u, long long int v, long long int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const long long int N = 1e7 + 5;
long long int dis[N];

int main()
{
    long long int n, e;
    cin >> n >> e;

    vector<Edge> EdgeList;

    while (e--)
    {
        long long int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    long long int source;
    cin >> source;

    long long int t;
    cin >> t;

    bool negCycleDetected = false;

    while (t--)
    {
        long long int dest;
        cin >> dest;

        for (long long int i = 0; i <= n; i++)
        {
            dis[i] = 1e18+10;
        }

        dis[source] = 0;

        for (long long int i = 1; i <= n - 1; i++)
        {
            for (Edge ed : EdgeList)
            {
                long long int u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;

                if (dis[u] < 1e18+10 && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }

        if (!negCycleDetected)
        {
            for (Edge ed : EdgeList)
            {
                long long int u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;

                if (dis[u] < 1e18+10 && dis[u] + c < dis[v])
                {
                    negCycleDetected = true;
                    cout << "Negative Cycle Detected\n";
                    break;
                }
            }
        }

        if (!negCycleDetected && dis[dest] == 1e18+10)
        {
            cout << "Not Possible\n";
        }
        else if (!negCycleDetected)
        {
            cout << dis[dest] << endl;
        }
    }

    return 0;
}