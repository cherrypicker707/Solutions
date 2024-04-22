// Stickogon
// Codeforces Round 940 (Div. 2) and CodeCraft-23
// 1957 A

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
        std::map<int, int> a;
        for (int i = 0; i < n; i++)
        {
            int e;
            std::cin >> e;
            a[e]++;
        }

        int answer = 0;

        for (auto e : a)
            answer += (e.second / 3);

        std::cout << answer << '\n';
    }
}