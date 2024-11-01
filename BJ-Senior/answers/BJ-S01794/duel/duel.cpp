#include<iostream>
#include<algorithm>
using namespace std;
int n,maxa,ans;
int v[1000010];
int a[1000010],nex[1000010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        v[a[i]]++;
        if(a[i]!=a[i-1])
            nex[a[i-1]]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int t=nex[a[i]];
        while(v[t]==0&&t!=0)
            nex[a[i]]=t=nex[t];
        if(v[t]!=0)
            v[t]--,ans++;
    }
    cout<<n-ans;
    return 0;
}
