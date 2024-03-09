// Sasha and the Beautiful Array
// Codefores Round 926 (Div. 2)
// 1929 A

#include <bits/stdc++.h>
#define int long long

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie();
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
        int min = LLONG_MAX;
        int max = LLONG_MIN;
        for(int i = 0; i < n; i++)
        {
            int a;
            std::cin >> a;
            min = std::min(a, min);
            max = std::max(a, max);
        }
        std::cout << (max-min) << '\n';
    }
}