#include <bits/stdc++.h>
using namespace std;
int n,t,k,q,st[100005][2],l;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int tt=0;tt<t;tt++)
    {
        cin>>n>>k>>q;
        for(int i=0;i<n;i++)
        {
            cin>>l;
            for(int j=0;j<l;j++){int sj;cin>>sj;st[sj][0]++;if(!(j=0)){st[sj][1]=1;}}
        }
        for(int i=0;i<q;i++)
        {
            int r,c,ans=1;
            cin>>r>>c;
            if(st[c][0]==0){ans=0;}
            if(st[c][1]==0){ans=0;}

            cout<<ans<<endl;
        }
    }

    return 0;
}