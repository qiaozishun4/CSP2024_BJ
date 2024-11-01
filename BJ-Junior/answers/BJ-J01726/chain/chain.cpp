#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l,x;
vector <int> a[111111];
bool f(int o,int w,int s)
{
    if(w == 0)
    {
        return o == c;
    }
    for(int i = 1;i<=n;i++)
    {
        if(s == i) continue;
        for(int j = 0;j<a[i].size();j++)
        {
            if(a[i][j] == o)
            {
                int u = a[i].size();
                for(int p = j+1;p<min(j+k,u);p++)
                    if(f(a[i][p],w-1,i)) return true;
            }
        }
    }
    return false;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i = 1;i<=n;i++)
        {
            cin>>l;
            for(int j = 1;j<=l;j++)
            {
                cin>>x;
                a[i].push_back(x);
            }
        }
        while(q--)
        {
            cin>>r>>c;
            if(f(1,r,0)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
