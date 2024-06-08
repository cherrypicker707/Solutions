// Everything Nim
// Codeforces Round 941 (Div. 2)
// 1974 C

#include <bits/stdc++.h>
#define int long long

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
        int n;
        std::cin >> n;
        std::set<int> piles;
        for(int i = 0; i < n; i++)
        {
            int e;
            std::cin >> e;
            piles.insert(e);
        }

        int removed = 0;
        bool alicesTurn = true;
        bool gameFinished = false;
        for(auto e : piles)
        {
            if(e-removed>1)
            {
                if(alicesTurn)
                    std::cout << "Alice\n";
                else
                    std::cout << "Bob\n";
                gameFinished = true;
                break;
            }

            alicesTurn = !alicesTurn;
            removed = e;
        }

        if(!gameFinished)
        {
            if(alicesTurn)
                std::cout << "Bob\n";
            else
                std::cout << "Alice\n";
        }
    }
}