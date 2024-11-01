#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
int ma;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int pre=1;
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1]) ma=max(ma,i-pre),pre=i;
    ma=max(ma,n+1-pre);
    printf("%d\n",ma);
}