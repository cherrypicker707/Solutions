// A BIT of an Inequality
// Codeforces Round 940 (Div. 2) and CodeCraft-23
// 1957 D

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
        int n;
        std::cin >> n;
        std::vector<std::vector<bool>> array(n, std::vector<bool>(32, false));
        for(int i = 0; i < n; i++)
        {
            int element;
            std::cin >> element;

            for(int j = 0; j < 32; j++)
                array[i][j] = (element & (1 << j)) != 0;
        }

        std::vector<std::vector<int>> evenLeft(n, std::vector<int>(32, 0));
        std::vector<std::vector<int>> oddLeft(n, std::vector<int>(32, 0));
        std::vector<std::vector<int>> evenRight(n, std::vector<int>(32, 0));
        std::vector<std::vector<int>> oddRight(n, std::vector<int>(32, 0));
        for(int j = 0; j < 32; j++)
        {
            evenLeft[0][j] = 1;
            oddLeft[0][j] = 0;
            for(int i = 1; i < n; i++)
            {
                if(array[i - 1][j])
                {
                    evenLeft[i][j] = oddLeft[i - 1][j] + 1;
                    oddLeft[i][j] = evenLeft[i - 1][j];
                    continue;
                }

                evenLeft[i][j] = evenLeft[i - 1][j] + 1;
                oddLeft[i][j] = oddLeft[i - 1][j];
            }

            evenRight[n - 1][j] = 1;
            oddRight[n - 1][j] = 0;
            for(int i = n - 2; i >= 0; i--)
            {
                if(array[i + 1][j])
                {
                    evenRight[i][j] = oddRight[i + 1][j] + 1;
                    oddRight[i][j] = evenRight[i + 1][j];
                    continue;
                }

                evenRight[i][j] = evenRight[i + 1][j] + 1;
                oddRight[i][j] = oddRight[i + 1][j];
            }
        }

        std::vector<std::vector<int>> ways(n, std::vector<int>(32, 0));
        for(int j = 0; j < 32; j++)
        {
            for(int i = 0; i < n; i++)
                ways[i][j] = evenLeft[i][j] * oddRight[i][j] + oddLeft[i][j] * evenRight[i][j];
        }

        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            int msb = -1;
            for(int j = 31; j >= 0; j--)
            {
                if(array[i][j])
                {
                    msb = j;
                    break;
                }
            }

            answer += ways[i][msb];
        }

        std::cout << answer << '\n';
    }

    return 0;
}
