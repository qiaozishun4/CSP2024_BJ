#include<iostream>
using namespace std;

const int MXN=16;
int col[MXN],a[MXN];

void Solve()
{
    int n;cin>>n;int mx=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=(1<<n)-1;i++)
    {
        for(int j=1;j<=n;j++) col[j]=(i>>(j-1))&1;
        // for(int j=1;j<=n;j++) cout<<col[j]<<' '; cout<<endl;
        int l[2]={0,0},ret=0;
        for(int j=1;j<=n;j++)
        {
            if(l[col[j]]==a[j]) ret+=a[j];
            l[col[j]]=a[j];
        }mx=max(mx,ret);
    }cout<<mx<<endl;
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;
    while(T--) Solve();
}