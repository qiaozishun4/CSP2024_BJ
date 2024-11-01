#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<list>
#define endl '\n'
using namespace std;
int T;
int n,k,q,l[100005],r,c;
vector<int>p[100005];
//at least 5 points
void solve()
{
    for(int i=1;i<=n;i++)
    {
        int sz=p[i].size()-1;
        for(int j=0;j<=sz;j++)
        {
            if(p[i][j]==1)
            {
                for(int h=j+1;h<=min(sz,j+k-1);h++)
                {
                    if(p[i][h]==c)
                    {
                        cout<<1<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<0<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                int v;
                cin>>v;
                p[i].push_back(v);
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            if(r==1)
            {
                solve();
            }
            else cout<<0<<endl;
        }
        for(int i=1;i<=n;i++) p[i].clear();
    }
    return 0;
}

