#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;vector<int> a[N];
int main()
{
    freopen("chain.in","r",stdin);freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        int n,k,q;cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            a[i].clear();
            int l;cin>>l;
            for(int j=1,x;j<=l;j++) cin>>x,a[i].push_back(x);
        }
        while(q--)
        {
            int r,c;cin>>r>>c;bool flag=false;
            if(r==1)
            {
                for(int i=1;i<=n;i++)
                {
                    int pos=-1e9;
                    for(int j=0;j<a[i].size();j++)
                    {
                        if(a[i][j]==c) flag|=(j-pos+1<=k);
                        if(a[i][j]==1) pos=j;
                    }
                }
                cout<<flag<<"\n";
            }
            else cout<<"1\n";
        }
    }
    return 0;
}