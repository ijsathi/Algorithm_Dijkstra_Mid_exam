#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;
const int N = 1001; 
vector<vector<pair<long long int, long long int>>> adj(N);

void dijkstra(long long int src, long long int n, vector<long long int> &dist)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        long long int u = pq.top().second;
        long long int cost = pq.top().first;
        pq.pop();

        if (cost > dist[u])
        {
            continue;
        }

        for (auto edge : adj[u])
        {
            long long int v = edge.first;
            long long int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    long long int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    long long int q;
    cin >> q;

    while (q--)
    {
        long long int src, dis;
        cin >> src >> dis;

        vector<long long int> dist(n + 1, INF); 
        dijkstra(src, n, dist);

        if (dist[dis] == INF)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist[dis] << "\n";
        }
    }

    return 0;
}