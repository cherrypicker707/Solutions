// How does the rook move?
// Codeforces Round 940 (Div. 2) and CodeCraft-23
// 1957 C

#include <bits/stdc++.h>
#define int long long

#define M 1000000007LL

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

    std::vector<int> dp(300010, -1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < 300010; i++)
        dp[i] = (dp[i-1]+(2*(i-1)*dp[i-2])%M)%M;

    while(t--)
    {
        int n, k;
        std::cin >> n >> k;
        for(int i = 0; i < k; i++)
        {
            int e, f;
            std::cin >> e >> f;

            if(e==f)
            {
                n--;
                continue;
            }

            n -= 2;
        }

        std::cout << dp[n] << '\n';
    }
}