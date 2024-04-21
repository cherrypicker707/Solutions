// Make Equal Again
// Codeforces Round 925 (Div. 3)
// 1931 C

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
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];

        int prefixNumber = a[0];
        int prefixLength = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
                prefixLength++;
            else
                break;
        }

        int suffixNumber = a[n - 1];
        int suffixLength = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] == a[i + 1])
                suffixLength++;
            else
                break;
        }

        int answer = n - std::max(prefixLength, suffixLength);
        if (prefixNumber == suffixNumber)
            answer = std::max(n - prefixLength - suffixLength, 0LL);
        std::cout << answer << '\n';
    }
}