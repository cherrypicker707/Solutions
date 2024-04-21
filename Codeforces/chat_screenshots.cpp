// Chat Screenshots
// Codeforces Round 925 (Div. 3)
// 1931 F

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k, a, b;
        std::cin >> n >> k;
        std::vector<std::set<int>> edge(n);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> a;
                a--;
                if (j > 1)
                    edge[b].insert(a);
                b = a;
            }
        }

        std::vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++)
        {
            for (int v : edge[u])
            {
                indegree[v]++;
            }
        }

        std::queue<int> queue;
        for (int u = 0; u < n; u++)
        {
            if (indegree[u] == 0)
                queue.emplace(u);
        }

        int removed = 0;
        while (queue.size())
        {
            removed++;
            int u = queue.front();
            queue.pop();
            for (int v : edge[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue.emplace(v);
            }
        }

        if (removed == n)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}