// Nene's Game
// Codeforces Round 939 (Div. 2)
// 1956 A

#include <bits/stdc++.h>

#define int long long

std::set<int> a;
std::vector<int> n;
std::vector<int> dp;

int getValue(int n)
{
    if (dp[n] != -1)
        return dp[n];

    int v = std::distance(a.begin(), a.upper_bound(n));
    if (v == 0)
        dp[n] = n;
    else
        dp[n] = getValue(n - v);
    return dp[n];
}

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
        int k, q;
        std::cin >> k >> q;
        a = std::set<int>();
        for (int i = 0; i < k; i++)
        {
            int e;
            std::cin >> e;
            a.insert(e);
        }
        n = std::vector<int>(q);
        for (int i = 0; i < q; i++)
            std::cin >> n[i];
        dp = std::vector<int>(101, -1);

        for (int i = 0; i < q; i++)
        {
            std::cout << getValue(n[i]) << ' ';
        }
        std::cout << '\n';
    }
}