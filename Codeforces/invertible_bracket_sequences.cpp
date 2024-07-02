// Invertible Bracket Sequences
// Educational Codeforces Round 166 (Rated for Div. 2)
// 1976 D

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
        std::string sequence;
        std::cin >> sequence;

        int state = 0;
        int answer = 0;
        std::map<int, int> count;
        count[0]++;

        for(auto character : sequence)
        {
            state -= 1;
            if(character == '(')
                state += 2;

            answer += count[state];
            count[state]++;

            if(state > 0)
                count[ceil((float)state/2.0f)-1] = 0;
        }

        std::cout << answer << '\n';
    }

    return 0;
}
