// Nene and the MEX operator
// Codeforces Round 939 (Div. 2)
// 1956 D

#include <bits/stdc++.h>
#define int long long

std::vector<std::pair<int, int>> answer;
std::vector<int> a;
std::vector<int> dp;
std::vector<int> dpS;

void operate(int l, int r)
{
    answer.push_back({l, r});

    std::set<int> e;
    for (int i = l; i <= r; i++)
        e.insert(a[i]);

    int mex = 0;
    while (e.count(mex))
        mex++;

    for (int i = l; i <= r; i++)
        a[i] = mex;
}

void fix(int l, int r)
{
    if (l == r)
    {
        if (a[l] == 0)
            operate(l, r);
        else if (a[l] > 1)
        {
            operate(l, r);
            operate(l, r);
        }

        return;
    }

    for (int i = r - 1; i >= l; i--)
        fix(l, i);

    if (a[r])
        operate(r, r);
    operate(l, r);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie();
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    std::cin >> n;
    a = std::vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    dp = std::vector<int>(n + 1, 0);
    dpS = std::vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int v = dp[i - 1] + a[i];
        if (v > dp[i])
        {
            dp[i] = v;
            dpS[i] = -1;
        }

        for (int j = 1; j <= i; j++)
        {
            int v = (i - j + 1) * (i - j + 1) + dp[j - 1];
            if (v > dp[i])
            {
                dp[i] = v;
                dpS[i] = j;
            }
        }
    }

    std::vector<std::pair<int, int>> segment;
    int k = n;
    while (k > 0)
    {
        if (dpS[k] == -1)
        {
            k--;
            continue;
        }

        segment.push_back({dpS[k], k});
        k = dpS[k] - 1;
    }

    for (auto e : segment)
        fix(e.first, e.second);

    std::cout << dp[n] << ' ' << answer.size() << '\n';
    for (auto e : answer)
    {
        std::cout << e.first << ' ' << e.second << '\n';
    }
}