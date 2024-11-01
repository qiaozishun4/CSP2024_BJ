#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int n,a[N],k[N],cnt;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=cnt;j++)
        {
            if(a[i]>k[j]){flag=0;k[j]=a[i];break;}
        }
        if(flag)k[++cnt]=a[i];
    }
    cout<<cnt;
    return 0;
}
