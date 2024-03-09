// Counting Binary Strings
// Codeforces Round 919 (Div. 2)
// 1920 E

#include <bits/stdc++.h>
#define int long long
#define M 998244353

signed main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, k;
        std::cin >> n >> k;
        n++;
        std::vector<std::vector<int>> dp(n, std::vector<int>(k, 0));

        for(int i = 0; i < k; i++)
        {
            dp[0][i] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < k; j++)
            {
                for(int u = 0; u < k-j && i+(j+1)*(u+1)<n; u++)
                {
                    dp[i+(j+1)*(u+1)][u] += dp[i][j];
                    dp[i][j] %= M;
                }
            }
        }

        int answer = 0;
        for(int i = 0; i < k; i++)
        {
            answer += dp[n-1][i];
            answer %= M;
        }
        std::cout << answer << '\n';
    }
}