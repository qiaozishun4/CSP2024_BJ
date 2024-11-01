#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int t,n,k,q;
int l[N],s[N][N],r[N],c[N],v[N*2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(v,0,sizeof(v));
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
                if(j>=2) v[s[i][j]]=1;
            }
        }
        for(int i=1;i<=q;i++) cin>>r[i]>>c[i];
        for(int i=1;i<=q;i++)
        {
            if(v[c[i]]==1) cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}
