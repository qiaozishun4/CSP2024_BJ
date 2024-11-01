#include<bits/stdc++.h>
using namespace std;
int a[100010];
int box[100010];
int minn,maxn=-1e9,cnt;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    minn=n,cnt=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        box[a[i]]++;
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<maxn;i++)
    {
        if(cnt-box[i]>=box[i])
        {
            minn-=box[i];
            cnt-=(box[i]+box[i]);
        }
        else
            minn-=cnt;
    }
    printf("%d",minn);
    return 0;
}
