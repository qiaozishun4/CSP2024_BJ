#include<bits/stdc++.h>
using namespace std;
const int N=1E5+1;
int a[N],c[N],a1[N];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>c[i];
    int k=0,ls=n;
    while(ls)
    {
        ls>>=1;
        k++;
    }
    for(int i=1;i<=k;i++)
        cin>>ls;
    int T;
    cin>>T;
    while(T--)
    {
        int x[5];
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)
            a1[i]=(a[i]^x[i%4]);
        int cnt=1;
        for(int i=1;i<=n;i++)
            cnt^=i*a1[i];
        cout<<cnt<<endl;
    }
    return 0;
}
//orz