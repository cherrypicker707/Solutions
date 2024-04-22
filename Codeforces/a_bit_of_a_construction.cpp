// A BIT of a Construction
// Codeforces Round 940 (Div. 2) and CodeCraft-23
// 1957 B

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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> answer(n, 0);

        int p = 1;

        for (int i = 0; i < n; i++)
        {
            answer[i] = p;
            k -= p;

            p *= 2;
            if (p > k)
                break;
        }

        answer[n - 1] += k;

        for (auto e : answer)
            std::cout << e << ' ';
        std::cout << '\n';
    }
}