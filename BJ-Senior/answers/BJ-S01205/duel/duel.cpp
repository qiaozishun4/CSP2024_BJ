#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int a[100010];
int b[100010];
int anss = 0;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    int maxr = -1;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[a[i]]++;
        maxr = max(a[i], maxr);
    }
    for(int i = 1; i <= maxr; i++)
    {
        if(b[i - 1] > b[i])
        {
            b[i] = b[i - 1];
        }
    }
    anss = b[maxr];
    printf("%d\n", anss);
    return 0;
}
