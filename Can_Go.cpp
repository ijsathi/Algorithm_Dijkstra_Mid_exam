#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e7;
vector<pair<long long int , long long int >> v[N];
long long int dis[N];

class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<long long int, long long int> parent = pq.top();
        pq.pop();

        long long int node = parent.first;
        long long int cost = parent.second;

        for (pair<long long int, long long int> child : v[node])
        {
            long long int childNode = child.first;
            long long int childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    long long int n;
    long long int e;
    cin >> n;
    cin >> e;

    while (e--)
    {
        long long int a, b;
        long long int c;
        cin >> a >> b;
        cin >> c;
        v[a].push_back({b, c});
    }

    int source;
    cin >> source;

    int t;
    cin >> t;

    while (t--)
    {
        long long int dest, maxCost;
        cin >> dest >> maxCost;

        for (int i = 1; i <= n; i++)
        {
            dis[i] = 1e18;
        }

        dijkstra(source);

        if (dis[dest] <= maxCost && dis[dest] != 1e18)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
