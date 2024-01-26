// I. etap XXXI OI
// CZAT BBB
// 50/100
// WERSJA 2.

#include <bits/stdc++.h>

#define int long long
#define ull unsigned long long
#define M ULLONG_MAX

std::string next(std::string f, char s)
{
    if(!s) s = 'a';
    return f.substr(1, f.size()-1)+s;
}

ull expo(ull n, ull k)
{
    if(k==0) return 1;
    ull half = expo(n, k/2);
    if(k%2==0) return (half*half)%M;
    return (((half*half)%M)*n)%M;
}

ull hash(std::string s)
{
    ull result = 0;
    ull n = s.size();
    for(ull i = 0; i < n; i++)
    {
        result += (s[i]-'a'+1)*expo(27, n-i-1);
        result %= M;
    }
    return result;
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

    std::map<ull, std::map<char, int>> frequency;
    std::map<ull, char> graph;

    ull h = hash(s.substr(0, k));

    for(int i = 0; i < n-k; i++)
    {
        frequency[h][s[i+k]]++;
        h -= ((s[i]-'a'+1)*expo(27, k-1));
        h *= 27;
        h += (s[i+k]-'a'+1);
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

    std::map<ull, bool> visited;
    std::vector<char> tail;
    std::vector<char> cycle;
    std::string current = s.substr(n-k, k);
    current = next(current, graph[hash(current)]);

    while(!visited[hash(current)])
    {
        visited[hash(current)] = true;
        current = next(current, graph[hash(current)]);
    }
    visited.clear();
    std::string cycleBeginning = current;

    current = s.substr(n-k, k);
    current = next(current, graph[hash(current)]);
    while(current!=cycleBeginning)
    {
        tail.emplace_back(current[current.size()-1]);
        current = next(current, graph[hash(current)]);
    }
    do
    {
        cycle.emplace_back(current[current.size()-1]);
        current = next(current, graph[hash(current)]);
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