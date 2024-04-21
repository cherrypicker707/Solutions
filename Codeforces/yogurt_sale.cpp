// Yogurt Sale
// Codeforces Round 938 (Div. 3)
// 1955 A

#include <bits/stdc++.h>

#define int long long

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, a, b;
        std::cin >> n >> a >> b;
        int answer = 0;
        if (b < 2 * a)
        {
            answer += (n / 2) * b;
            answer += (n % 2) * a;
            std::cout << answer << '\n';
            continue;
        }
        answer += n * a;
        std::cout << answer << '\n';
    }

    return 0;
}