// Divisible Pairs
// Codeforces Round 925 (Div. 3)
// 1931 D

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
        int n, x, y;
        std::cin >> n >> x >> y;
        std::vector<int> a(n);
        std::vector<int> aModuloX(n);
        std::vector<int> aModuloY(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            aModuloX[i] = a[i]%x;
            aModuloY[i] = a[i]%y;
        }

        std::map<int,std::map<int,int>> frequency;

        int answer = 0;
        for(int i = 0; i < n; i++)
        {
            int mX = aModuloX[i];
            int mY = aModuloY[i];
            answer += frequency[(x-mX)%x][mY];
            frequency[mX][mY]++;
        }

        std::cout << answer << '\n';
    }
}