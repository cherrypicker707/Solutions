// Paired Up
// USACO 2017 US Open Contest
// Silver

#include <bits/stdc++.h>

int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i].second >> a[i].first;
    }
    std::sort(a.begin(), a.end());
    int i = 0;
    int j = n-1;
    int answer = 0;
    while(i<=j&&i<n&&j>=0)
    {
        answer = std::max(answer, a[i].first+a[j].first);
        int amount = std::min(a[i].second, a[j].second);
        a[i].second -= amount;
        a[j].second -= amount;
        if(a[i].second<=0) i++;
        if(a[j].second<=0) j--;
    }

    std::cout << answer << '\n';
}