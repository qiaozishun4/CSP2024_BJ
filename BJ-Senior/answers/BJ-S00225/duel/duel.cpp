#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N]={0},d[N]={0},r=0,mx=0,k=0;
int tt=0,ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    memset(a,0,sizeof(0));
    for(int i=0;i<n;i++)
    {
        cin>>r;
        a[r]++;
        mx=max(mx,r);
    }
    for(int i=0;i<=mx;i++)
    {
        if(a[i]!=0)
        {
            d[k]=a[i];
            k++;
        }
    }
    int mon[k+1],m=0;
    for(int i=0;i<k;i++) mon[i]=d[i];
    int b=1;
    while(b<k)
    {
        if(d[b]>=mon[m])
        {
            mon[m]=-1;
            m++;
            if(b==m) b++;
        }
        if(d[b]<mon[m])
        {
            mon[m]-=d[b];
            b++;
        }
    }

    for(int i=0;i<k;i++)
    {
        if(mon[i]!=-1) ans+=mon[i];
    }
    cout<<ans;
    return 0;
}
