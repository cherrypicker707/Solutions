// I. etap XXX OI.
// ZBOŻE
// 15/100

#include <bits/stdc++.h>

#define int long long

std::vector<std::vector<std::pair<int,int>>> edge;
std::vector<int> subtreeSize;
std::vector<int> parent;
std::vector<int> length;
std::vector<int> castles;
std::vector<int> paths;
std::vector<int> sCastles;
std::vector<int> sPaths;

int dfs1(int v, int p)
{
    int result = 1;
    for(auto e : edge[v])
    {
        if(e.first!=p)
        {
            result += dfs1(e.first, v);
        }
    }
    subtreeSize[v] = result;
    return result;
}

void dfs2(int v, int p, int l)
{
    parent[v] = p;
    length[v] = l;
    for(auto e : edge[v])
    {
        if(e.first!=p)
        {
            dfs2(e.first, v, e.second);
        }
    }
}

signed main()
{
    int n, k;
    std::cin >> n >> k;
    edge = std::vector<std::vector<std::pair<int,int>>>(n);
    for(int i = 0; i < n-1; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    subtreeSize = std::vector<int>(n);
    dfs1(0, -1);

    parent = std::vector<int>(n);
    length = std::vector<int>(n);
    dfs2(0, -1, 0);

    int root = 0;
    int bsta = 0;
    int value = 0;
    do
    {
        root = bsta;
        bsta = -1;
        value = n-subtreeSize[root];
        for(auto e : edge[root])
        {
            if(e.first!=parent[root])
            {
                value = std::max(value, subtreeSize[e.first]);
                if(bsta==-1||subtreeSize[e.first]>subtreeSize[bsta])
                {
                    bsta = e.first;
                }
            }
        }
    }while(value>(n/2));

    dfs2(root, -1, 0);

    castles = std::vector<int>(n, 0);
    paths = std::vector<int>(n, 0);
    
    int u = 0;
    int d = 0;
    while(u>=0)
    {
        castles[u]++;
        paths[u] += d;
        d += length[u];
        u = parent[u];
    }

    int answer = 0;
    for(int i = 0; i < k; i++)
    {
        int v;
        std::cin >> v;
        v--;

        int distance = 0;
        int previous = -1;
        int previousCastles = 0;
        int previousLength = 0;
        int previousPaths = 0;
        while(v>=0)
        {
            int nCastles = castles[v];
            nCastles -= previousCastles;  
            int nPaths = paths[v];
            nPaths -= (previousCastles*previousLength+previousPaths);

            answer += nCastles*distance+nPaths;

            previousCastles = castles[v];
            previousPaths = paths[v];
            previousLength = length[v];
            castles[v]++;
            paths[v] += distance;
            distance += length[v];

            v = parent[v];
        }

        std::cout << 2*answer << '\n';
    }
}