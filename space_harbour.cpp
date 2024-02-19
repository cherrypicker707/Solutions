// Space Harbour
// Codeforces Round 921 (Div. 1)
// 1924 B

#include <bits/stdc++.h>
#define int long long

struct Point
{
    Point() {this->x = this->y = 0;}
    Point(int x, int y) {this->x=x; this->y=y;};
    int x, y;
};

std::vector<int> initCost;
std::vector<int> tree;
std::vector<Point> lazy;

void constructTree(int u, int sl, int sr)
{
    if(sl==sr)
    {
        tree[u] = initCost[sl];
        return;
    }

    int sm = (sl+sr)/2;
    constructTree(2*u+1, sl, sm);
    constructTree(2*u+2, sm+1, sr);
    tree[u] = tree[2*u+1] + tree[2*u+2];
    return;
}

void updateTree(int u, int sl, int sr, int ul, int ur, Point value)
{
    int span = sr-sl+1;
    if(lazy[u].x!=0||lazy[u].y!=0)
    {
        tree[u] += span*lazy[u].x;
        tree[u] += ((span*(span-1LL))/2LL)*lazy[u].y;
        if(span>1)
        {
            lazy[2*u+2].x += lazy[u].x;
            lazy[2*u+2].y += lazy[u].y;
            int d = sr-((sl+sr)/2);
            lazy[u].x += (d*lazy[u].y);
            lazy[2*u+1].x += lazy[u].x;
            lazy[2*u+1].y += lazy[u].y;
        }
        lazy[u].x = 0;
        lazy[u].y = 0;
    }

    if(ur<ul||ul>sr||ur<sl) return;

    if(sl>=ul&&sr<=ur)
    {
        tree[u] += span*value.x;
        tree[u] += ((span*(span-1LL))/2LL)*value.y;
        if(span>1)
        {
            lazy[2*u+2].x += value.x;
            lazy[2*u+2].y += value.y;
            int d = sr-((sl+sr)/2);
            value.x += (d*value.y);
            lazy[2*u+1].x += value.x;
            lazy[2*u+1].y += value.y;
        }
        return;
    }

    int sm = (sl+sr)/2;
    updateTree(2*u+2, sm+1, sr, ul, ur, value);
    if(ur>sm)
    {
        int d = std::min(sr, ur)-sm;
        value.x += d*value.y;
    }
    updateTree(2*u+1, sl, sm, ul, ur, value);
    tree[u] = tree[2*u+1]+tree[2*u+2];
}

int queryTree(int u, int sl, int sr, int ql, int qr)
{
    int span = sr-sl+1;
    if(lazy[u].x!=0||lazy[u].y!=0)
    {
        tree[u] += span*lazy[u].x;
        tree[u] += ((span*(span-1LL))/2LL)*lazy[u].y;
        if(span>1)
        {
            lazy[2*u+2].x += lazy[u].x;
            lazy[2*u+2].y += lazy[u].y;
            int d = sr-((sl+sr)/2);
            lazy[u].x += (d*lazy[u].y);
            lazy[2*u+1].x += lazy[u].x;
            lazy[2*u+1].y += lazy[u].y;
        }
        lazy[u].x = 0;
        lazy[u].y = 0;
    }

    if(qr<ql||ql>sr||qr<sl) return 0;

    if(sl>=ql&&sr<=qr) return tree[u];

    int sm = (sl+sr)/2;
    return queryTree(2*u+1, sl, sm, ql, qr)+queryTree(2*u+2, sm+1, sr, ql, qr);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> x(m);
    std::vector<int> v(m);
    for(int i = 0; i < m; i++) std::cin >> x[i];
    for(int i = 0; i < m; i++) std::cin >> v[i];
    std::set<int> harbourPosition;
    std::vector<int> harbourValue(n);
    for(int i = 0; i < m; i++)
    {
        x[i]--;
        harbourPosition.insert(x[i]);
        harbourValue[x[i]] = v[i];
    }

    initCost = std::vector<int>(n);
    int currentDistance = 0;
    for(int i = 0; i < n; i++)
    {
        if(harbourPosition.count(i)) initCost[i] = harbourValue[i];
        else initCost[i] = initCost[i-1];
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(harbourPosition.count(i)) currentDistance = 0;
        else
        {
            currentDistance++;
        }
        initCost[i] *= currentDistance;
    }

    int treeSize = 1;
    while(treeSize<n) treeSize <<= 1;
    treeSize <<= 1;
    tree = std::vector<int>(treeSize, 0);
    lazy = std::vector<Point>(treeSize, Point());
    constructTree(0, 0, n-1);

    for(int i = 0; i < q; i++)
    {
        int t, a, b;
        std::cin >> t >> a >> b;
        if(t==1)
        {
            a--;
            harbourValue[a] = b;
            auto iterator = harbourPosition.lower_bound(a);
            int next = (*iterator);
            iterator--;
            int previous = (*iterator);
            Point leftSide(harbourValue[previous]*(a-next), 0);
            Point rightSide(0, harbourValue[a]-harbourValue[previous]);
            updateTree(0, 0, n-1, previous+1, a, leftSide);
            updateTree(0, 0, n-1, a+1, next, rightSide);
            harbourPosition.insert(a);
        }
        else
        {
            a--;
            b--;
            std::cout << queryTree(0, 0, n-1, a, b) << '\n';
        }
    }
}