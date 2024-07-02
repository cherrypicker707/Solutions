// Reverse Card (Easy Version)
// Codeforces Round 942 (Div. 2)
// 1972 D1

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

    while(t--)
    {
        int n, m;
        std::cin >> n >> m;

        int answer = 0;
        for(int b = 1; b <= m; b++)
        {
            for(int a = b; a <= n; a += b)
            {
                if((a + b) % (b * std::gcd(a, b)) == 0)
                    answer++;
            }
        }

        std::cout << answer << '\n';
    }

    return 0;
}
