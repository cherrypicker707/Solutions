// Anna and Valentine's Day Gift
// Codeforces Round 925 (Div. 3)
// 1931 E

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
        int n, m;
        std::cin >> n >> m;
        int sum = 0;
        int minZero = 9;
        std::vector<int> zero(n);
        for (int i = 0; i < n; i++)
        {
            std::string s;
            std::cin >> s;
            int z = 0;
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == '0')
                    z++;
                else
                    break;
            }
            sum += (s.size());
            minZero = std::min(minZero, z);
            zero[i] = z;
        }

        std::sort(zero.begin(), zero.end(), std::greater<int>());

        int p = 0;
        int removed = 0;
        for (int i = 0; i < n; i++)
        {
            if (p >= n || zero[p] == 0)
                break;

            removed += zero[p];
            p++;

            if (p >= n || zero[p] == 0)
                break;

            p++;
        }

        int answer = sum - removed;
        std::cout << (answer >= (m + 1) ? "Sasha" : "Anna") << '\n';
    }
}