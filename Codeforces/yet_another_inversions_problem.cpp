// Yet Another Inversion Problem
// Codeforces Round 917 (Div. 2)
// 1917 D

#include <bits/stdc++.h>
#define int long long
#define LOGN 20
#define M 998244353

class SegmentTree
{
public:
    SegmentTree(int n)
    {
        this->n = n;
        tree = std::vector<int>(2 * n, 0);
    }
    void set(int p, int v)
    {
        p += n;
        tree[p] = v % M;
        p /= 2;

        while (p >= 1)
        {
            tree[p] = (tree[2 * p] + tree[2 * p + 1]) % M;
            p /= 2;
        }
    }
    void add(int p, int v)
    {
        p += n;
        tree[p] = (tree[p] + v) % M;
        p /= 2;

        while (p >= 1)
        {
            tree[p] = (tree[2 * p] + tree[2 * p + 1]) % M;
            p /= 2;
        }
    }
    int query(int l, int r)
    {
        l += n;
        r += n;

        int result = 0;
        while (l <= r)
        {
            if (l % 2 == 1)
            {
                result += tree[l];
                result %= M;
                l++;
            }
            if (r % 2 == 0)
            {
                result += tree[r];
                result %= M;
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return result % M;
    }

private:
    int n;
    std::vector<int> tree;
};

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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> p(n);
        std::vector<int> q(k);
        for (int i = 0LL; i < n; i++)
            std::cin >> p[i];
        for (int i = 0LL; i < k; i++)
            std::cin >> q[i];

        SegmentTree innerST(k);
        int innerInversions = 0LL;
        for (int i = 0LL; i < k; i++)
        {
            if (q[i] < k - 1LL)
                innerInversions += innerST.query(q[i] + 1LL, k - 1LL);
            innerST.set(q[i], 1LL);
        }

        SegmentTree amountST(n);
        SegmentTree inversionST(n);
        std::vector<int> shift(LOGN, 0LL);
        std::vector<int> position(2LL * n, 0LL);
        std::vector<int> previousElement(LOGN, 1LL);
        int outerInversions = 0LL;
        for (int i = 0LL; i < k && i < LOGN; i++)
        {
            int d = k - i + 1LL;
            shift[i] = (d * (d - 1LL)) / 2LL;
            shift[i] %= M;
        }
        for (int i = 0LL; i < n; i++)
        {
            position[p[i]] = i;
        }

        for (int i = 0LL; i < n; i++)
        {
            int c = 2LL * i + 1LL;
            for (int j = 0; j < LOGN && j < k; j++)
            {
                while (previousElement[j] * (1LL << j) < c)
                {
                    inversionST.set(position[previousElement[j]], shift[j + 1]);
                    previousElement[j] += 2;
                }
            }

            if (position[c] > 0LL)
                outerInversions += inversionST.query(0LL, position[c] - 1LL);
            outerInversions %= M;
            if (position[c] < n - 1LL)
            {
                int all = amountST.query(position[c] + 1LL, n - 1LL);
                int ksq = (k * k) % M;
                all = (ksq * all) % M;
                int subtract = inversionST.query(position[c] + 1LL, n - 1LL);
                outerInversions += (M + all - subtract) % M;
                outerInversions %= M;
            }

            amountST.set(position[c], 1LL);
            inversionST.set(position[c], shift[1]);
        }

        int answer = (n * innerInversions) % M;
        answer += outerInversions;
        answer %= M;
        std::cout << answer << '\n';
    }
}