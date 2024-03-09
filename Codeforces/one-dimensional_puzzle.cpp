// One-Dimensional Puzzle
// Codeforces Round 925 (Div. 3)
// 1931 G

#include <bits/stdc++.h>
#define int long long
#define M 998244353

std::vector<int> factorial;

int binpow(int n, int k)
{
    if(k==0) return 1LL;
    int result = binpow(n, k/2);
    result = (result*result)%M;
    if(k%2==1) result = (n*result)%M;
    return result;
}

int newton(int n, int k)
{
    int numerator = factorial[n];
    int denominator = (factorial[k]*factorial[n-k])%M;
    denominator = binpow(denominator, M-2);
    int answer = (numerator*denominator)%M;
    return answer;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie();
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    factorial = std::vector<int>(4000001);
    factorial[0] = 1LL;
    for(int i = 1; i < 4000001; i++)
    {
        factorial[i] = (i*factorial[i-1])%M;
    }

    int t;
    std::cin >> t;
    while(t--)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;

        if(a==0&&b==0)
        {
            if(c!=0&&d!=0) std::cout << 0 << '\n';
            else std::cout << 1 << '\n';
        }
        else if(a==b)
        {
            int p = a;
            int answer1 = (newton(p+c-1, c)*newton(p+d, d))%M;
            int answer2 = (newton(p+c, c)*newton(p+d-1, d))%M;
            int answer = (answer1+answer2)%M;
            std::cout << answer << '\n';
        }
        else if(a-b==1||b-a==1)
        {
            int p = std::max(a, b);
            int answer = (newton(p+c-1, c)*newton(p+d-1, d))%M;
            std::cout << answer << '\n';
        }
        else
        {
            std::cout << 0 << '\n';
        }
    }
}