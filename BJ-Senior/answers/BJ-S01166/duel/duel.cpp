#include <bits/stdc++.h>
using namespace std;
int const N=1e5+3;
int a[N],n;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int i=1,j=2,cnt=0;
    while(i<=n && j<=n)
    {
        while(j<=n && a[j]==a[i]) ++j;
        if(j>n) break;
        ++cnt,++i,++j;
    }
    printf("%d\n",n-cnt);
    return 0;
}