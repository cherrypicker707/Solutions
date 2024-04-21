// Mischevious Shooter
// Codeforces Round 920 (Div. 3)
// 1921 G

#include <bits/stdc++.h>
#define int long long
#define M 1000000007LL

std::vector<std::vector<int>> a;
int n, m, k;

bool prov(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

int process()
{
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> diagonal(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> vertical(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vertical[i][j] += a[i][j];
            if (i > 0)
                vertical[i][j] += vertical[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            diagonal[i][j] += a[i][j];
            if (i > 0 && j < m - 1)
                diagonal[i][j] += diagonal[i - 1][j + 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] += vertical[i][j];
            if (i - k - 1 >= 0)
                dp[i][j] -= vertical[i - k - 1][j];
            if (j - 1 >= 0)
            {
                dp[i][j] += dp[i][j - 1];
                int d = j - k - 1;
                if (d >= 0)
                    dp[i][j] -= diagonal[i][d];
                else if (i + d >= 0)
                    dp[i][j] -= diagonal[i + d][0];
                if (i - k - 1 >= 0)
                    dp[i][j] += diagonal[i - k - 1][j];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result = std::max(result, dp[i][j]);
        }
    }

    return result;
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
        std::cin >> n >> m >> k;
        // k++
        a = std::vector<std::vector<int>>(n, std::vector<int>(m));
        std::vector<std::vector<char>> input(n, std::vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> input[i][j];
            }
        }

        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = (input[i][j] == '#');
            }
        }
        answer = std::max(answer, process());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = (input[n - 1 - i][j] == '#');
            }
        }
        answer = std::max(answer, process());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = (input[i][m - 1 - j] == '#');
            }
        }
        answer = std::max(answer, process());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = (input[n - 1 - i][m - 1 - j] == '#');
            }
        }
        answer = std::max(answer, process());

        std::cout << answer << '\n';
    }
}