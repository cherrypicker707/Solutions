// Job Interview
// Educational Codeforces Round 166 (Rated for Div. 2)
// 1957 D

#include <bits/stdc++.h>
#define int long long

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

    while(t--)
    {
        std::vector<int> places(2);
        std::cin >> places[0] >> places[1];
        int allPlaces = places[0] + places[1];
        std::vector<std::vector<int>> skill(2, std::vector<int>(allPlaces + 1));
        for(int i = 0; i < allPlaces + 1; i++)
            std::cin >> skill[0][i];
        for(int i = 0; i < allPlaces + 1; i++)
            std::cin >> skill[1][i];

        std::vector<bool> type(allPlaces + 1, 0);
        std::vector<int> hired(2, 0);
        int total = 0;

        int special = -1;

        for(int i = 0; i < allPlaces; i++)
        {
            bool currentType = 0;
            if(skill[0][i] < skill[1][i])
                currentType = 1;

            if(hired[currentType] < places[currentType])
            {
                type[i] = currentType;
                hired[currentType]++;
                total += skill[currentType][i];
                continue;
            }

            if(special == -1)
                special = i;

            currentType = !currentType;

            type[i] = currentType;
            hired[currentType]++;
            total += skill[currentType][i];
        }

        for(int i = 0; i < allPlaces + 1; i++)
        {
            if(special != -1 && i < special && type[i] != type[special])
            {
                int change = 0;
                change -= skill[type[i]][i];
                change -= skill[!type[i]][special];
                change += skill[type[i]][special];
                change += skill[!type[i]][allPlaces];
                std::cout << (total + change) << ' ';
                continue;
            }

            int change = 0;
            change -= skill[type[i]][i];
            change += skill[type[i]][allPlaces];
            std::cout << (total + change) << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
