// Minimizing the Sum
// Educational Codeforces Round 165 (Div. 2)
// 1969 C

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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];

        std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, LLONG_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                int m = LLONG_MAX;
                for (int l = i - j; l <= i; l++)
                    if (l >= 0)
                        m = std::min(m, a[l]);

                for (int l = 0; l <= k; l++)
                {
                    if (l - j < 0)
                        continue;

                    int value = 0;
                    if (i - j - 1 >= 0)
                        value += dp[i - j - 1][l - j];

                    value += m * (std::min(i, j) + 1);
                    dp[i][l] = std::min(dp[i][l], value);
                }
            }
        }

        int answer = dp[n - 1][k];
        std::cout << answer << '\n';
    }
}