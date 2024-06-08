// Turtle and Incomplete Sequence
// Codeforces Round 949 (Div. 2)
// 1981 C

#include <bits/stdc++.h>
#define int long long

int getLCA(int x, int y)
{
    while ((int)log2(x) > (int)log2(y))
        x /= 2;

    while ((int)log2(x) < (int)log2(y))
        y /= 2;

    while (x != y)
    {
        x /= 2;
        y /= 2;
    }

    return x;
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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        std::vector<int> v;
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
            if (a[i] != -1)
                v.push_back(i);
        }

        if (v.size() == 0)
        {
            for (int i = 0; i < n; i++)
                std::cout << (1 + (i % 2)) << ' ';
            std::cout << '\n';
            continue;
        }

        int leftValue = a[v[0]];
        for (int i = v[0] - 1; i >= 0; i--)
        {
            a[i] = leftValue;
            if (a[i + 1] == leftValue)
                a[i] *= 2;
        }

        int rightValue = a[v[v.size() - 1]];
        for (int i = v[v.size() - 1] + 1; i < n; i++)
        {
            a[i] = rightValue;
            if (a[i - 1] == rightValue)
                a[i] *= 2;
        }

        bool valid = true;
        for (int i = 0; i < v.size() - 1; i++)
        {
            int left = v[i];
            int right = v[i + 1];
            int lca = getLCA(a[left], a[right]);
            int distance = right - left;
            int path = (int)log2(a[left]) + (int)log2(a[right]) - 2 * (int)log2(lca);

            if (path > distance || (distance - path) % 2 == 1)
            {
                valid = false;
                break;
            }

            int p;

            p = left;
            while (a[p] != lca)
            {
                p++;
                a[p] = a[p - 1] / 2;
            }

            p = right;
            while (a[p] != lca)
            {
                p--;
                a[p] = a[p + 1] / 2;
            }

            for (int j = left; j <= right; j++)
            {
                if (a[j] != -1)
                    continue;

                a[j] = lca;
                if (a[j - 1] == lca)
                    a[j] *= 2;
            }
        }

        if (!valid)
        {
            std::cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < n; i++)
            std::cout << a[i] << ' ';
        std::cout << '\n';
    }
}