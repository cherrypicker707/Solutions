// Sasha and the Drawing
// Codefores Round 926 (Div. 2)
// 1929 B

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
        int n, k, answer;
        std::cin >> n >> k;
        int p = n + std::max(n - 2, 0LL);
        if (k <= (p * 2))
            answer = ceil((double)k / 2);
        else
            answer = k - p;
        std::cout << answer << '\n';
    }
}