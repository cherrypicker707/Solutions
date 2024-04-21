// Light Bulbs (Hard Version)
// Codefores Round 916 (Div. 3)
// 1914 G2

#include <bits/stdc++.h>
#define int long long
#define M 998244353

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::mt19937_64 rand(M);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> hash(n);
        std::vector<int> array(2 * n);
        for (int i = 0; i < n; i++)
        {
            int r = 0;
            while (r == 0)
                r = rand();
            hash[i] = r;
        }
        for (int i = 0; i < 2 * n; i++)
        {
            std::cin >> array[i];
            array[i]--;
        }

        std::map<int, int> hashHistory;
        std::vector<bool> segmentEnd(2 * n, false);
        std::vector<bool> innerStart(2 * n, false);
        std::vector<bool> innerStop(2 * n, false);
        int currentHash = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            currentHash ^= hash[array[i - 1]];
            if (hashHistory[currentHash] != 0)
            {
                innerStart[hashHistory[currentHash]] = true;
                innerStop[i - 1] = true;
            }
            if (currentHash == 0)
            {
                segmentEnd[i - 1] = true;
            }
            else
            {
                hashHistory[currentHash] = i;
            }
        }

        int count = 0;
        int answer1 = 0;
        int answer2 = 1;
        int inner = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (innerStart[i])
                inner++;
            if (inner <= 0)
                count++;
            if (innerStop[i])
                inner--;
            if (segmentEnd[i])
            {
                answer1++;
                answer2 = (count * answer2) % M;
                count = 0;
            }
        }

        std::cout << answer1 << ' ' << answer2 << '\n';
    }
}