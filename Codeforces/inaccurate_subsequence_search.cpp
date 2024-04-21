// Inaccurate Subsequence Search
// Codeforces Round 938 (Div. 3)
// 1955 D

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
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<int> a(n);
        std::map<int, int> b;

        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        for (int i = 0; i < m; i++)
        {
            int p;
            std::cin >> p;
            b[p]++;
        }

        int answer = 0;

        std::map<int, int> current;
        int currentCount = 0;
        for (int i = 0; i < m; i++)
        {
            if (current[a[i]] < b[a[i]])
                currentCount++;
            current[a[i]]++;
        }

        if (currentCount >= k)
            answer++;

        for (int i = m; i < n; i++)
        {
            current[a[i - m]]--;
            if (current[a[i - m]] < b[a[i - m]])
                currentCount--;

            if (current[a[i]] < b[a[i]])
                currentCount++;
            current[a[i]]++;

            if (currentCount >= k)
                answer++;
        }

        std::cout << answer << '\n';
    }

    return 0;
}