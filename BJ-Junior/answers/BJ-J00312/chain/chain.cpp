#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag1,ans1[200005];
int t,n,k,q,l[100005],r[100005],c[100005];
vector<int> s[100005];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        flag1=0;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            int x;
            for(int j=1;j<=l[i];j++)
            {
                cin>>x;
                s[i].push_back(x);
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            if(r[i]!=1)flag1=1;
        }
        if(!flag1)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=l[i];j++)
                {
                    if(--cnt>0)ans1[s[i][j]]=1;
                    if(s[i][j]==1)cnt=k;
                }
            }
            for(int i=1;i<=q;i++)
            {
                cout<<ans1[c[i]]<<endl;
            }
        }
        memset(ans1,0,sizeof(ans1));
        memset(s,0,sizeof(s));
    }
    return 0;
}
