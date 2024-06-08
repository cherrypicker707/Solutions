// Nikita and LCM
// Codeforces Round 947 (Div. 1 + Div. 2)
// 1977 C

#include <bits/stdc++.h>
#define int long long

int n;
std::vector<int> a;

int getArrayLCM()
{
    int lcm = 0;
    for (int i = 0; i < n; i++)
    {
        if (lcm == 0)
            lcm = a[i];
        else
            lcm = std::lcm(lcm, a[i]);

        if (lcm > a[n - 1])
            return LLONG_MAX;
    }

    return lcm;
}

int getSubsequenceLength(int expectedLCM)
{
    int length = 0;
    int currentLCM = 0;

    for (int i = 0; i < n; i++)
    {
        if (expectedLCM % a[i] == 0)
        {
            length++;
            if (currentLCM == 0)
                currentLCM = a[i];
            else
                currentLCM = std::lcm(currentLCM, a[i]);
        }
    }

    if (currentLCM != expectedLCM)
        return 0;

    return length;
}

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
        std::cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());

        int maxValue = a[n - 1];

        int fullArrayLCM = getArrayLCM();
        if (fullArrayLCM > maxValue)
        {
            std::cout << n << '\n';
            continue;
        }

        std::set<int> a_set;
        for (int i = 0; i < n; i++)
            a_set.insert(a[i]);

        int root = ceil(sqrt(maxValue));

        int answer = 0;
        for (int i = 1; i <= root; i++)
        {
            if (maxValue % i == 0)
            {
                int x = i;
                int y = maxValue / i;

                if (!a_set.count(x))
                    answer = std::max(answer, getSubsequenceLength(x));
                if (!a_set.count(y))
                    answer = std::max(answer, getSubsequenceLength(y));
            }
        }

        std::cout << answer << '\n';
    }
}
