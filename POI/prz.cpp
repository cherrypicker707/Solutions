// I. stage of XXXI POI
// PRZYCISKI
// 100/100

#include <bits/stdc++.h>
#define int long long

std::vector<std::vector<std::pair<int,int>>> adjacency;

bool done = false;
int loop = -1;
std::set<int> evenSet;
std::vector<bool> evenVisited;
bool dfsEven(int u, int p)
{
    evenVisited[u] = true;

    for(auto edge : adjacency[u])
    {
        int v = edge.first;
        int s = edge.second;

        if(v == p)
            continue;

        if(done)
            break;

        if(evenVisited[v])
        {
            evenSet.insert(s);
            done = true;
            loop = v;
            return true;
        }

        if(dfsEven(v, u))
        {
            evenSet.insert(s);

            if(loop == u)
                return false;
            return true;
        }
    }

    return false;
}

std::set<int> oddSet;
std::vector<bool> oddVisited;
bool dfsOdd(int u, int p)
{
    if(oddVisited[u])
        return true;
    oddVisited[u] = true;

    int children = 0;
    for(auto edge : adjacency[u])
    {
        int v = edge.first;
        int s = edge.second;
        
        if(v == p)
            continue;

        if(!dfsOdd(v, u))
        {
            children++;
            oddSet.insert(s);
        }
    }

    return (children % 2);
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    std::cin >> n >> m;
    adjacency.resize(2 * n);
    for(int i = 0; i < m; i++)
    {
        int r, c;
        std::cin >> r >> c;
        r = r - 1;
        c = c - 1 + n;

        adjacency[r].push_back({c, i + 1});
        adjacency[c].push_back({r, i + 1});
    }

    evenVisited.resize(2 * n, false);
    for(int i = 0; i < 2 * n; i++)
    {
        if(!done && !evenVisited[i])
            dfsEven(i, -1);
    }

    if(evenSet.size())
    {
        std::cout << "TAK\n";
        std::cout << evenSet.size() << '\n';
        for(auto e : evenSet)
            std::cout << e << ' ';
        std::cout << '\n';

        return 0;
    }

    bool valid = true;
    oddVisited.resize(2 * n, false);
    for(int i = 0; i < 2 * n; i++)
        valid = valid && dfsOdd(i, -1);

    if(!valid)
    {
        std::cout << "NIE\n";
        
        return 0;
    }

    std::cout << "TAK\n";
    std::cout << oddSet.size() << '\n';
    for(auto e : oddSet)
        std::cout << e << ' ';
    std::cout << '\n';

    return 0;
}
