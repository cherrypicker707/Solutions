// We Got Everything Covered!
// Codefores Round 921 (Div. 2)
// 1925 A

#include <bits/stdc++.h>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        int n, k;
        std::cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                std::cout << (char)('a' + j);
            }
        }
        std::cout << '\n';
    }
    return 0;
}