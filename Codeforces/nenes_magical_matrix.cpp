// Nene's Magical Matrix
// Codeforces Round 939 (Div. 2)
// 1956 C

#include <bits/stdc++.h>

#define int long long

signed main()
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
        int n;
        std::cin >> n;

        int sum = 0;

        for (int i = n; i >= 1; i--)
            sum += ((2 * i - 1) * i);

        std::cout << sum << ' ' << (2 * n) << '\n';

        for (int i = n; i >= 1; i--)
        {
            std::cout << 1 << ' ' << i << ' ';
            for (int j = 1; j <= n; j++)
                std::cout << j << ' ';
            std::cout << '\n';

            std::cout << 2 << ' ' << i << ' ';
            for (int j = 1; j <= n; j++)
                std::cout << j << ' ';
            std::cout << '\n';
        }
    }
}