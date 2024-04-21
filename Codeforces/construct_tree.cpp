// Construct Tree
// Codeforces Round 917 (Div. 2)
// 1917 F

#include <bits/stdc++.h>
#define int long long
#define D 2001

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
        int n, d;
        std::cin >> n >> d;
        std::vector<int> l(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> l[i];
        }
        std::vector<std::bitset<D>> dp(D);

        std::sort(l.begin(), l.end());

        if (n > 1 && (l[n - 1] + l[n - 2]) > d)
        {
            std::cout << "No\n";
            continue;
        }

        dp[0][0] = 1;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = d; j >= 0; j--)
            {
                if (j >= l[i])
                    dp[j] = (dp[j] | dp[j - l[i]] | (dp[j] << l[i]));
                else
                    dp[j] = (dp[j] | dp[j] << l[i]);
            }
        }

        int valid = false;
        for (int i = l[n - 1]; i <= d - l[n - 1]; i++)
        {
            if (dp[i][d - i])
            {
                valid = true;
                break;
            }
        }

        if (valid)
        {
            std::cout << "Yes\n";
            continue;
        }

        for (int i = d; i >= 0; i--)
        {
            if (i >= l[n - 1])
                dp[i] = (dp[i - l[n - 1]] | (dp[i] << l[n - 1]));
            else
                dp[i] = (dp[i] << l[n - 1]);
        }

        for (int i = 0; i <= d; i++)
        {
            if (dp[i][d - i])
            {
                valid = true;
                break;
            }
        }

        if (valid)
        {
            std::cout << "Yes\n";
            continue;
        }

        std::cout << "No\n";
    }
}