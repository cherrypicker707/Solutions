// Cat, Fox and Double Maximum
// Codeforces Round 945 (Div. 2)
// 1973 C

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
        int n;
        std::cin >> n;
        std::vector<int> p(n, 0);
        std::vector<int> rP(n + 1, 0);
        std::vector<int> q(n, 0);

        bool winning = false;

        for (int i = 0; i < n; i++)
        {
            std::cin >> p[i];

            rP[p[i]] = i;

            if (p[i] == n)
                winning = (i % 2);
        }

        std::set<int> winningNumbers;
        std::set<int> losingNumbers;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == winning)
                winningNumbers.insert(p[i]);
            else
                losingNumbers.insert(p[i]);
        }

        int c = n / 2;
        for (int e : losingNumbers)
        {
            q[rP[e]] = c;
            c--;
        }

        int d = n;
        for (int e : winningNumbers)
        {
            q[rP[e]] = d;
            d--;
        }

        for (int i = 0; i < n; i++)
        {
            std::cout << q[i] << ' ';
        }
        std::cout << '\n';
    }
}