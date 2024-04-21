// 01 Tree
// Hello 2024
// 1919 D

#include <bits/stdc++.h>
#define int long long

int n;
std::vector<int> a;
std::vector<int> l;
std::vector<int> r;
std::vector<bool> inQueue;

bool canBeRemoved(int i)
{
    return (i >= 0 && i <= n) && (a[i] - a[l[i]] == 1 || a[i] - a[r[i]] == 1);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        a = std::vector<int>(n + 2);
        l = std::vector<int>(n + 2);
        r = std::vector<int>(n + 2);
        inQueue = std::vector<bool>(n + 2);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            l[i] = i - 1;
            r[i] = i + 1;
            inQueue[i] = false;
        }
        a[0] = LLONG_MIN;
        a[n + 1] = LLONG_MIN;

        std::priority_queue<std::pair<int, int>> queue;
        for (int i = 1; i <= n; i++)
        {
            if (canBeRemoved(i))
            {
                queue.push({a[i], i});
                inQueue[i] = true;
            }
        }

        while (queue.size())
        {
            int i = queue.top().second;
            queue.pop();
            r[l[i]] = r[i];
            l[r[i]] = l[i];
            if (!inQueue[l[i]] && canBeRemoved(l[i]))
            {
                queue.push({a[l[i]], l[i]});
                inQueue[l[i]] = true;
            }
            if (!inQueue[r[i]] && canBeRemoved(r[i]))
            {
                queue.push({a[r[i]], r[i]});
                inQueue[r[i]] = true;
            }
        }

        int rest = 0;
        int zero = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!inQueue[i])
            {
                rest++;
                zero += (a[i] == 0);
            }
        }

        if (rest == 1 && zero == 1)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}