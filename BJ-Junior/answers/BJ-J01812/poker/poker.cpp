#include <cstdio>
#include <iostream>
using namespace std;

const int N = 505;

bool a[N][N];
int l[4] = {int('D'), int('C'), int('H'), int('S')};
int s[13] = {int('A'), int('2'), int('3'), int('4'), int('5'), int('6'), int('7'), int('8'), int('9'), int('T'), int('J'), int('Q'), int('K')};

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char op, x;
        cin >> op >> x;
        a[op][x] = true;
    }
    int cnt = 0;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 12; j++)
        {
            if (!a[l[i]][s[j]]) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
