#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int r,n;
int sumv=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&r);
        ++a[r];
    }
    for(int i=1;i<=100000;++i)
    {
        sumv-=min(sumv,a[i]);
        sumv+=a[i];
    }
    printf("%d",sumv);
    return 0;
}
