#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,res,r[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
    }
    sort(r+1,r+1+n);
    int w=0;
    res=n;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(j<n&&r[1+j]==r[i])
        {
            j++;
        }
        int cnt=j-i+1;
        int t=min(cnt,w);
        res-=t;
        w+=(cnt-t);
        i=j;
    }
    printf("%d",res);
    return 0;
}