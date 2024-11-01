#include<bits/stdc++.h>
using namespace std;

int n;
int a[100010];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,ans=n;
    for(int i=2;i<=n;i++)
    {
        if(a[l]!=a[i])
        {
            l++;
            ans--;
        }
    }
    printf("%d\n",ans);
    return 0 ;
}