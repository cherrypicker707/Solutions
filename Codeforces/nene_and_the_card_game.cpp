// Nene and the Card Game
// Codeforces Round 939 (Div. 2)
// 1956 B

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
        std::vector<bool> a(n, false);
        int score = 0;
        for (int i = 0; i < n; i++)
        {
            int e;
            std::cin >> e;
            e--;
            if (a[e])
                score++;
            else
                a[e] = true;
        }

        std::cout << score << '\n';
    }
}