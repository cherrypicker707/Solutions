// Make Equal
// Codeforces Round 925 (Div. 3)
// 1931 B

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
        int n, sum = 0;
        std::cin >> n;
        std::vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            sum += a[i];
        }

        int expectedAmount = sum/n;

        int suffixSum = 0;
        bool valid = true;
        for(int i = n-1; i >= 0; i--)
        {
            suffixSum += a[i];
            double dSS = suffixSum;
            double dN = n-i;
            int currentAmount = ceil(dSS/dN);
            if(currentAmount>expectedAmount)
            {
                valid = false;
                break;
            }
        }

        std::cout << (valid?"YES":"NO") << '\n';
    }
}