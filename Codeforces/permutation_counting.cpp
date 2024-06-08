// Permutation Counting
// Codeforces Round 942 (Div. 2)
// 1972 C

#include <bits/stdc++.h>
#define int long long

signed main()
{
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
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());

        std::vector<int> c(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
                c[i] += (a[i + 1] - a[i]) * (i + 1);
            if (i > 0)
                c[i] += c[i - 1];
        }

        int p = 0;
        for (int i = 1; i < n; i++)
            if (c[i - 1] <= k)
                p = i;

        int l = a[p];
        if (p > 0)
            k -= c[p - 1];
        l += (k / (p + 1));
        int e = n - p - 1 + (k % (p + 1));

        int q = l * n + e;

        int answer = q - n + 1;

        std::cout << answer << '\n';
    }
}