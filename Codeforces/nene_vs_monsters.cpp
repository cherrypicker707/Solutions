// Nene vs. Monsters (Easy Version)
// Codeforces Round 939 (Div. 2)
// 1956 E1

#include <bits/stdc++.h>
#define int long long

int n;
std::vector<int> a;

void simulate()
{
    for (int i = 0; i < n; i++)
        a[(i + 1) % n] = std::max(0LL, a[(i + 1) % n] - a[i]);
}

bool all()
{
    for (int i = 0; i < n; i++)
        if (a[i] == 0)
            return false;

    return true;
}

bool moreThanTwo()
{
    int count = 0;

    for (int i = 0; i < n + 3; i++)
    {
        if (a[i % n] > 0)
            count++;
        else
            count = 0;

        if (count > 2)
            return true;
    }

    return false;
}

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
    while (t--)
    {
        std::cin >> n;
        a = std::vector<int>(n);
        for (int i = 0; i < n; i++)
            std::cin >> a[i];

        std::vector<int> answer;

        if (n < 4)
        {
            while (all())
                simulate();

            for (int i = 0; i < n; i++)
                if (a[i] > 0 && a[(i - 1 + n) % n] == 0)
                    answer.push_back(i + 1);
        }
        else
        {
            while (moreThanTwo())
                simulate();

            for (int i = 0; i < n; i++)
                if (a[i] > 0 && a[(i - 1 + n) % n] == 0)
                    answer.push_back(i + 1);
        }

        std::cout << answer.size() << '\n';
        for (int e : answer)
            std::cout << e << ' ';
        std::cout << '\n';
    }
}