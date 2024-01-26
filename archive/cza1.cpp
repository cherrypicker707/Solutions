// I. etap XXXI OI
// CZAT BBB
// 50/100
// WERSJA 1.

#include <bits/stdc++.h>

#define int long long

std::string next(std::string f, char s)
{
    if(!s) s = 'a';
    return f.substr(1, f.size()-1)+s;
}

signed main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, k, a, b;
    std::string s;
    std::cin >> n >> k >> a >> b >> s;
    a -= n;
    b -= n;

    std::map<std::string, std::map<char, int>> frequency;
    std::map<std::string, char> graph;

    for(int i = 0; i < n-k; i++)
    {
        frequency[s.substr(i, k)][s[i+k]]++;
    }

    for(auto e : frequency)
    {
        char l = 'a';
        int t = 0;
        for(auto f : e.second)
        {
            if(f.second>t)
            {
                l = f.first;
                t = f.second;
            }
        }
        graph[e.first] = l;
    }

    frequency.clear();

    std::map<std::string, bool> visited;
    std::vector<char> tail;
    std::vector<char> cycle;
    std::string current = s.substr(n-k, k);
    current = next(current, graph[current]);

    while(!visited[current])
    {
        visited[current] = true;
        current = next(current, graph[current]);
    }
    visited.clear();
    std::string cycleBeginning = current;

    current = s.substr(n-k, k);
    current = next(current, graph[current]);
    while(current!=cycleBeginning)
    {
        tail.emplace_back(current[current.size()-1]);
        current = next(current, graph[current]);
    }
    do
    {
        cycle.emplace_back(current[current.size()-1]);
        current = next(current, graph[current]);
    }   while(current!=cycleBeginning);

    int position = a;
    bool isCycle = false;
    for(int i = 0; i < (b-a+1); i++)
    {
        if(!isCycle&&position>tail.size())
        {
            isCycle = true;
            position -= tail.size();
        }
        if(isCycle&&position>cycle.size())
        {
            position %= cycle.size();
            if(position==0) position = cycle.size();
        }

        if(!isCycle)
        {
            std::cout << tail[position-1];
        }
        else
        {
            std::cout << cycle[position-1];
        }

        position++;
    }
    std::cout << '\n';
}