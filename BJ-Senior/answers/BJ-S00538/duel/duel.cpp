#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n, a[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1, a+n+1);
    int cur = 1; //now the previous undefeated
    int ans = 0;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] > a[cur])
        {
            ans++;
            cur++;
        }
    }
    printf("%d\n",n - ans);
    return 0;
}