// Progressive Square
// Codeforces Round 938 (Div. 3)
// 1955 B

#include <bits/stdc++.h>

#define int long long

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, c, d;
        std::cin >> n >> c >> d;
        int nn = n * n;
        std::map<int, int> a;
        std::map<int, int> b;
        int u = LLONG_MAX;

        for (int i = 0; i < nn; i++)
        {
            int p;
            std::cin >> p;
            a[p]++;
            u = std::min(u, p);
        }

        int x = u;
        for (int i = 0; i < n; i++)
        {
            int y = x;
            for (int j = 0; j < n; j++)
            {
                b[y]++;
                y += d;
            }
            x += c;
        }

        bool valid = true;
        for (auto e : a)
        {
            int key = e.first;
            if (a[key] != b[key])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            std::cout << "YES\n";
            continue;
        }
        std::cout << "NO\n";
    }

    return 0;
}