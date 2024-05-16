// Permutation Game
// Codeforces Round 943 (Div. 3)
// 1968D

#include <bits/stdc++.h>
#define int long long

std::vector<int> graph;
std::vector<int> profit;

int finalScore(int initialNode, int k)
{
    int node = initialNode;
    int l = 0;
    std::set<int> visited;
    while (!visited.count(node) && l < k)
    {
        visited.insert(node);
        node = graph[node];
        l++;
    }

    std::vector<int> path(l);
    std::vector<int> pathPrefix(l);

    node = initialNode;

    for (int i = 0; i < l; i++)
    {
        path[i] = profit[node];
        node = graph[node];
    }

    for (int i = 0; i < l; i++)
    {
        pathPrefix[i] = path[i];
        if (i > 0)
            pathPrefix[i] += pathPrefix[i - 1];
    }

    int score = k * path[0];
    for (int i = 1; i < l; i++)
        score = std::max(score, pathPrefix[i - 1] + (k - i) * path[i]);

    return score;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k, bodyaPosition, sashaPosition;
        std::cin >> n >> k >> bodyaPosition >> sashaPosition;
        bodyaPosition--;
        sashaPosition--;
        graph.resize(n, 0);
        profit.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            std::cin >> graph[i];
            graph[i]--;
        }
        for (int i = 0; i < n; i++)
            std::cin >> profit[i];

        int bodyaScore = finalScore(bodyaPosition, k);
        int sashaScore = finalScore(sashaPosition, k);

        if (bodyaScore > sashaScore)
            std::cout << "Bodya\n";
        else if (sashaScore > bodyaScore)
            std::cout << "Sasha\n";
        else
            std::cout << "Draw\n";
    }
}