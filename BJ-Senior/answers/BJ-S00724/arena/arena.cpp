#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int aa[100010];
int p[100010];
char c[20][70010];
int a[150010];
int xx[4];
int maxn[150010];
int maxid[150010];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>aa[i];
    for(int i=1;i<=m;i++)cin>>p[i];
    int K=0;
    while((1<<K)<n)K++;
    for(int i=K;i>=1;i--)
        for(int j=1;j<=(1<<i-1);j++)
            cin>>c[i][j];
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<4;i++)cin>>xx[i];
        for(int i=1;i<=n;i++)
            a[i]=(aa[i]^xx[i%4]);
        for(int i=1;i<=n;i++)
            if(a[i]>maxn[i-1])
                maxn[i]=a[i],maxid[i]=i;
            else maxn[i]=maxn[i-1],maxid[i]=maxid[i-1];
        int sum=0;
        for(int i=1;i<=m;i++)sum^=maxid[p[i]];
        cout<<sum<<endl;
    }
    return 0;
}