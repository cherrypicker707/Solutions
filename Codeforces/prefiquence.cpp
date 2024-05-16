// Prefiquence
// Codeforces Round 943 (Div. 3)
// 1968B

#include <bits/stdc++.h>
#define int long long

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
        int n, m;
        std::cin >> n >> m;
        std::vector<char> a(n);
        std::vector<char> b(m);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        for (int i = 0; i < m; i++)
            std::cin >> b[i];

        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            char currentBit = a[i];
            while (j < m && b[j] != currentBit)
                j++;

            if (j < m)
            {
                i++;
                j++;
            }
        }

        std::cout << i << '\n';
    }
}