// Beauty of the Mountains
// Codeforces Round 955 (Div. 2, with prizes from NEAR!)
// 1982 D

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

    while(t--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<std::vector<int>> height(n, std::vector<int>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                std::cin >> height[i][j];
        }

        std::vector<std::vector<bool>> snow(n, std::vector<bool>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                char e;
                std::cin >> e;
                snow[i][j] = (e == '1');
            }
        }

        std::vector<std::vector<int>> row(n, std::vector<int>(m, 0));
        for(int i = 0; i < n; i++)
        {
            row[i][0] = snow[i][0];
            for(int j = 1; j < m; j++)
                row[i][j] = row[i][j - 1] + snow[i][j];
        }

        std::vector<std::vector<int>> column(n, std::vector<int>(m, 0));
        for(int j = 0; j < m; j++)
        {
            column[0][j] = snow[0][j];
            for(int i = 1; i < n; i++)
                column[i][j] = column[i - 1][j] + snow[i][j];
        }

        std::vector<int> sumOfSnow(n - k + 1, 0);
        for(int i = 0; i < k; i++)
            sumOfSnow[0] += row[i][k - 1];

        std::set<int> matrix;

        for(int i = 0; i < n - k + 1; i++)
        {
            if(i > 0)
            {
                sumOfSnow[i] = sumOfSnow[i - 1];
                sumOfSnow[i] -= row[i - 1][k - 1];
                sumOfSnow[i] += row[i + k - 1][k - 1];
            }

            int currentSum = sumOfSnow[i];
            matrix.insert(abs(k * k - 2 * currentSum));

            for(int j = 1; j < m - k + 1; j++)
            {
                currentSum += column[i + k - 1][j + k - 1];
                currentSum -= column[i + k - 1][j - 1];

                if(i > 0)
                {
                    currentSum -= column[i - 1][j + k - 1];
                    currentSum += column[i - 1][j - 1];
                }

                matrix.insert(abs(k * k - 2 * currentSum));
            }
        }

        // !!!
        int gcd = 0;
        for(int e : matrix)
            gcd = std::gcd(gcd, e);

        std::vector<int> sumOfHeights(2, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                sumOfHeights[snow[i][j]] += height[i][j];
        }

        int difference = abs(sumOfHeights[0] - sumOfHeights[1]);

        if(difference == 0)
        {
            std::cout << "YES\n";
            continue;
        }

        if(gcd == 0 || difference % gcd)
        {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
    }

    return 0;
}
