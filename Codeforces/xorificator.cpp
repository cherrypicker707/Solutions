// XORificator
// Codeforces Round 948 (Div. 2)
// 1977 D

#include <bits/stdc++.h>
#define int long long

std::mt19937_64 mersenne(975329753297);

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<bool>> a(n, std::vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char e;
                std::cin >> e;
                if (e == '1')
                    a[i][j] = true;
            }
        }

        std::vector<int> h(n);
        for (int i = 0; i < n; i++)
            h[i] = mersenne();

        std::map<int, int> count;

        for (int i = 0; i < m; i++)
        {
            int hash = 0;
            for (int j = 0; j < n; j++)
                hash ^= (a[j][i] * h[j]);

            for (int j = 0; j < n; j++)
            {
                hash ^= h[j];
                count[hash]++;
                hash ^= h[j];
            }
        }

        int answer = 0;
        for (auto e : count)
            answer = std::max(answer, e.second);

        std::cout << answer << '\n';

        int row = -1;
        int column = -1;
        for (int i = 0; i < m; i++)
        {
            int hash = 0;
            for (int j = 0; j < n; j++)
                hash ^= (a[j][i] * h[j]);

            for (int j = 0; j < n; j++)
            {
                hash ^= h[j];
                if (count[hash] == answer)
                {
                    column = i;
                    row = j;
                    break;
                }
                hash ^= h[j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i][column] && i != row)
            {
                std::cout << 1;
                continue;
            }

            if (!a[i][column] && i == row)
            {
                std::cout << 1;
                continue;
            }

            std::cout << 0;
        }

        std::cout << '\n';
    }
}
