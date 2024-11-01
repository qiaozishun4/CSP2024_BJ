#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int r[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &r[i]);
    }
    sort(r+1,r+n+1);
    int cur1=1, cur2=2;
    int dead = 0;
    for(cur1=1;cur1<=n;cur1++)
    {
        while(cur2<=n && r[cur2]<=r[cur1]) cur2++;
        if(r[cur2]>r[cur1]){dead++;cur2++;}
    }
    printf("%d", n-dead);
    return 0;
}
