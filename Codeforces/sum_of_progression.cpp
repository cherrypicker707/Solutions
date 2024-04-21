// Sum of Progression
// Codeforces Round 920 (Div. 3)
// 1921 F

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
        int n, q;
        std::cin >> n >> q;
        int f = sqrt(n);
        std::vector<int> array(n);
        for (int i = 0; i < n; i++)
            std::cin >> array[i];
        std::vector<std::vector<int>> prefixSum(f, std::vector<int>(n, 0));
        std::vector<std::vector<int>> prefixSumMultilplied(f, std::vector<int>(n, 0));

        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j - i - 1 >= 0)
                    prefixSum[i][j] = prefixSum[i][j - i - 1];
                prefixSum[i][j] += array[j];
                if (j - i - 1 >= 0)
                    prefixSumMultilplied[i][j] = prefixSumMultilplied[i][j - i - 1];
                prefixSumMultilplied[i][j] += (j / (i + 1) + 1) * array[j];
            }
        }

        for (int i = 0; i < q; i++)
        {
            int s, d, k;
            std::cin >> s >> d >> k;
            if (d <= f)
            {
                int answer = 0;
                if (s - 1 + d * (k - 1) < n)
                {
                    answer += prefixSumMultilplied[d - 1][s - 1 + d * (k - 1)];
                    answer -= ((s - 1) / d) * prefixSum[d - 1][s - 1 + d * (k - 1)];
                }
                if (s - 1 - d >= 0)
                {
                    answer -= prefixSumMultilplied[d - 1][s - 1 - d];
                    answer += ((s - 1) / d) * prefixSum[d - 1][s - 1 - d];
                }
                std::cout << answer << ' ';
            }
            else
            {
                int answer = 0;
                int m = 1;
                int c = s - 1;
                for (int j = 0; j < k; j++)
                {
                    answer += m * array[c];
                    m++;
                    c += d;
                }
                std::cout << answer << ' ';
            }
        }

        std::cout << "\n";
    }
}