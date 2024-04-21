// I. stage of XXXI POI
// CZAT BBB
// 50/100

#include <bits/stdc++.h>
#define int long long
#define A 26LL
#define M 10000000000000000LL

int value(char c)
{
    return 1LL + c - 'a';
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
    a = a - n - 1;
    b = b - n - 1;

    int hashsum = 0LL;
    int modifier = 1LL;
    for (int i = k - 1LL; i >= 0LL; i--)
    {
        hashsum = (hashsum + value(s[i]) * modifier) % M;
        hashsum %= M;
        if (i > 0)
            modifier = (A * modifier) % M;
    }
    std::map<int, std::map<char, int>> occurencies;
    for (int i = k; i < n; i++)
    {
        occurencies[hashsum][s[i]]++;

        int subtract = (value(s[i - k]) * modifier) % M;
        hashsum = (hashsum - subtract + M) % M;
        hashsum = (A * hashsum) % M;
        hashsum = (hashsum + value(s[i])) % M;
    }

    std::map<int, char> nextChar;
    for (auto e : occurencies)
    {
        int h = e.first;
        char c = 'a';
        int t = 0LL;
        for (auto f : e.second)
        {
            if (f.second > t)
            {
                t = f.second;
                c = f.first;
            }
        }
        nextChar[h] = c;
    }

    std::vector<char> toRemove(k);
    int removePointer = 0LL;
    for (int i = 0; i < k; i++)
    {
        toRemove[i] = s[n - k + i];
    }

    int beginning = hashsum;

    int count = 0LL;
    std::set<int> visited;
    while (!visited.count(hashsum))
    {
        count++;
        visited.insert(hashsum);
        char next = nextChar[hashsum];
        if (!next)
            next = 'a';

        int subtract = (value(toRemove[removePointer]) * modifier) % M;
        toRemove[removePointer] = next;
        removePointer = (removePointer + 1LL) % k;
        hashsum = (hashsum - subtract + M) % M;
        hashsum = (A * hashsum) % M;
        hashsum = (hashsum + value(next)) % M;
    }

    int loop = hashsum;

    hashsum = beginning;
    removePointer = 0LL;
    for (int i = 0LL; i < k; i++)
    {
        toRemove[i] = s[n - k + i];
    }

    bool beforeCycle = true;
    int loopPosition = 0LL;
    std::vector<char> sequence(count);
    for (int i = 0; i < count; i++)
    {
        if (hashsum == loop)
            loopPosition = i;

        char next = nextChar[hashsum];
        if (!next)
            next = 'a';
        sequence[i] = next;

        int subtract = (value(toRemove[removePointer]) * modifier) % M;
        toRemove[removePointer] = next;
        removePointer = (removePointer + 1LL) % k;
        hashsum = (hashsum - subtract + M) % M;
        hashsum = (A * hashsum) % M;
        hashsum = (hashsum + value(next)) % M;
    }

    int cycleLength = count - loopPosition;
    int position = a;
    if (position >= count)
    {
        position -= loopPosition;
        position %= cycleLength;
        position += loopPosition;
    }
    for (int i = 0LL; i < (b - a + 1LL); i++)
    {
        std::cout << sequence[position];
        position++;
        if (position == count)
            position = loopPosition;
    }

    return 0;
}