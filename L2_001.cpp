#include <iostream>
#include <climits>
#include <stack>
using namespace std;

const int INFINITE = INT_MAX;
int cities[500] = {0};
int graph[500][500];

int main()
{
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    for (int i = 0; i < N; i++)
        cin >> cities[i];
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            graph[i][j] = INFINITE;

    for (int i = 0; i < M; i++)
    {
        int source, destination;
        cin >> source >> destination;
        cin >> graph[source][destination];
        graph[destination][source] = graph[source][destination];
    }

    // Dijkstra
    int* path = new int[N];
    int* dist = new int[N];
    int* weight = new int[N];
    bool* collected = new bool[N];
    int* num = new int[N];
    for (int i = 0; i < N; i++)
    {
        path[i] = -1;
        dist[i] = INFINITE;
        collected[i] = false;
        weight[i] = 0;
    }

    // Initialize
    dist[S] = 0;
    collected[S] = true;
    weight[S] = cities[S];
    num[S] = 1;
    for (int i = 0; i < N; i++)
    {
        if (graph[S][i] != INFINITE)
        {
            dist[i] = graph[S][i];
            path[i] = S;
            weight[i] = cities[S] + cities[i];
            num[i] = 1;
        }
    }

    while (true) {
        int val = INFINITE, min = -1;
        for (int i = 0; i < N; i++)
        {
            if (!collected[i] && dist[i] < val)
            {
                val = dist[i];
                min = i;
            }
        }
        if (min == -1) break;
        collected[min] = true;
        for (int i = 0; i < N; i++)
        {
            if (!collected[i] && graph[min][i] != INFINITE)
            {
                if (graph[min][i] + dist[min] < dist[i])
                {
                    dist[i] = graph[min][i] + dist[min];
                    path[i] = min;
                    weight[i] = weight[min] + cities[i];
                    num[i] = num[min];
                }
                else if (graph[min][i] + dist[min] == dist[i])
                {
                    num[i] += num[min];
                    if (weight[min] + cities[i] > weight[i])
                    {
                        path[i] = min;
                        weight[i] = weight[min] + cities[i];
                    }
                }
            }
        }
    }

    stack<int> s;
    int total = 0;
    int p = D;
    while (p != -1)
    {
        total += cities[p];
        s.push(p);
        p = path[p];
    }
    cout << num[D] << " " << total << endl;
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
        if (s.size() != 0) cout << " ";
    }
    cout << endl;
    return 0;
}
