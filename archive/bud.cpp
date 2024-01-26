// I. etap XXXI OI
// BUDOWANIE LOTNISKA
// 100/100

#include <bits/stdc++.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    char a;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> area(n, std::vector<bool>(n));
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            std::cin >> a;
            area[i][j] = (a=='.');
        }
    }

    std::vector<int> sumLeft(n);
    std::vector<int> sumRight(n);
    std::vector<int> sumUp(n);
    std::vector<int> sumDown(n);

    for(int j = 0; j < n; j++)
    {
        int v = 0;
        for(int i = 0; i < n; i++)
        {
            if(!area[i][j]) v = 0;
            else v++;
            sumLeft[i] = std::max(sumLeft[i], v);
            sumUp[j] = std::max(sumUp[j], v);
        }
    }

    for(int j = 0; j < n; j++)
    {
        int v = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(!area[i][j]) v = 0;
            else v++;
            sumRight[i] = std::max(sumRight[i], v);
            sumDown[j] = std::max(sumDown[j], v);
        }
    }

    for(int i = 0; i < n; i++)
    {
        int v = 0;
        for(int j = 0; j < n; j++)
        {
            if(!area[i][j]) v = 0;
            else v++;
            sumUp[j] = std::max(sumUp[j], v);
            sumLeft[i] = std::max(sumLeft[i], v);
        }
    }

    for(int i = 0; i < n; i++)
    {
        int v = 0;
        for(int j = n-1; j >= 0; j--)
        {
            if(!area[i][j]) v = 0;
            else v++;
            sumDown[j] = std::max(sumDown[j], v);
            sumRight[i] = std::max(sumRight[i], v);
        }
    }

    for(int i = 1; i < n; i++)
    {
        sumLeft[i] = std::max(sumLeft[i], sumLeft[i-1]);
        sumUp[i] = std::max(sumUp[i], sumUp[i-1]);
    }

    for(int i = n-2; i >= 0; i--)
    {
        sumRight[i] = std::max(sumRight[i], sumRight[i+1]);
        sumDown[i] = std::max(sumDown[i], sumDown[i+1]);
    }

    int answer = 0;

    if(m==2)
    {
        for(int i = 1; i < n; i++)
        {
            answer = std::max(answer, std::min(sumLeft[i-1], sumRight[i]));
            answer = std::max(answer, std::min(sumUp[i-1], sumDown[i]));
        }
    }
    else
    {
        answer = std::max(sumRight[0], sumDown[0]);
    }

    std::cout << answer << '\n';
}