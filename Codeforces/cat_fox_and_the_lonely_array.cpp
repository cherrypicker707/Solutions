// Cat, Fox and The Lonely Array
// Codeforces Round 945 (Div. 2)
// 1973 B

#include <bits/stdc++.h>
#define int long long

std::vector<int> a;

bool check(int k)
{
    int n = a.size();

    std::vector<int> bitCount(20, 0);

    for (int i = 0; i < k; i++)
    {
        int x = a[i];

        for (int j = 0; j < 20; j++)
            if (x & (1 << j))
                bitCount[j]++;
    }

    int hash = 0;
    for (int i = 0; i < 20; i++)
        if (bitCount[i])
            hash += (1 << i);

    for (int i = k; i < n; i++)
    {
        int x = a[i - k];

        for (int j = 0; j < 20; j++)
            if (x & (1 << j))
                bitCount[j]--;

        int y = a[i];

        for (int j = 0; j < 20; j++)
            if (y & (1 << j))
                bitCount[j]++;

        int newHash = 0;
        for (int i = 0; i < 20; i++)
            if (bitCount[i])
                newHash += (1 << i);

        if (newHash != hash)
            return false;
    }

    return true;
}

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
        a.resize(n, 0);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];

        int answer = LLONG_MAX;

        int left = 1;
        int right = n;
        while (left <= right)
        {
            int middle = (left + right) / 2;

            if (check(middle))
            {
                answer = std::min(answer, middle);
                right = middle - 1;
                continue;
            }

            left = middle + 1;
        }

        std::cout << answer << '\n';
    }
}