// Recovering a Small String
// Codeforces Round 925 (Div. 3)
// 1931 A

#include <bits/stdc++.h>
#define int long long

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
        int n;
        std::cin >> n;

        int a1 = std::max(1LL, n - 52);
        n -= a1;
        int a2 = std::max(1LL, n - 26);
        n -= a2;
        int a3 = n;

        char c1 = 'a' + a1 - 1;
        char c2 = 'a' + a2 - 1;
        char c3 = 'a' + a3 - 1;
        std::cout << c1 << c2 << c3 << '\n';
    }
}