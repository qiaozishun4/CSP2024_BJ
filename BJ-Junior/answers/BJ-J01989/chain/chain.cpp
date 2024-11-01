#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
int T,n,k,q,r,c;
const int N=2e5+2;
vector<vector<int>> s;
int vis[105];
bool flag=0;
void dfs(int last,int step,int st)
{
    if(flag)return;
    if(step>r)
    {
        if(st==c)flag=1;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(i==last)continue;
        for(int j=1;j<s[i].size();++j)
        {
            if(s[i][j]==st)
            {
                for(int l=j+1;l<s[i].size();++l)
                {
                    if(l-j+1>k)break;
                    dfs(i,step+1,s[i][l]);
                    if(flag)return;
                }
            }
        }
    }
}
bool check()
{
    flag=0;
    dfs(-1,1,1);
    return flag;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        s.clear();
        cin>>n>>k>>q;
        s.push_back(vector<int>());
        for(int i=1;i<=n;++i)
        {
            s.push_back(vector<int>());
            int l;
            cin>>l;
            s[i].resize(l+1);
            for(int j=1;j<=l;++j)
            {
                cin>>s[i][j];
                vis[s[i][j]]++;
            }
        }
        for(int i=1;i<=q;++i)
        {
            cin>>r>>c;
            if(!vis[1]||!vis[c])
            {
                cout<<0<<endl;
                continue;
            }
            cout<<check()<<endl;
        }
    }
    return 0;
}
