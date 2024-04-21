// Binary Subsequences
// Codeforces Round 921 (Div. 1)
// 1924 D

#include <bits/stdc++.h>
#define int long long
#define M 1000000007LL

std::vector<int> factorial;

int binpow(int n, int k)
{
    if (k == 0)
        return 1;
    int result = binpow(n, k / 2);
    result = (result * result) % M;
    if (k % 2 == 1)
        result = (n * result) % M;
    return result;
}

int newton(int n, int k)
{
    int result = (factorial[k] * factorial[n - k]) % M;
    result = binpow(result, M - 2);
    result = (factorial[n] * result) % M;
    return result;
}

int f(int n, int m, int k)
{
    if (n <= k || m <= k)
        return newton(n + m, m);
    return newton(n + m, k);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    factorial = std::vector<int>(5000);
    factorial[0] = 1;
    for (int i = 1; i < 5000; i++)
    {
        factorial[i] = (i * factorial[i - 1]) % M;
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::cout << ((M + f(n, m, k) - f(n, m, k - 1)) % M) << '\n';
    }
}