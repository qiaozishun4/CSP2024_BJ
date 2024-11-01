#include <iostream>
#include <vector>
using namespace std;
int T,n,k,q,l[100005],r[100005],c[100005],mx;
bool f[105][100005];
vector<int> s[100005];
struct hi{int x,y;};
vector<hi> mp[200005];
void dfs(int d,int x,int y,int fx,int fy)
{
    if(d>mx) return;
    for(int i=y+1;i<l[x]&&i<y+k;i++)
    {
        int id=s[x][i],sz=mp[id].size();
        f[d][id]=1;
        for(int j=0;j<sz;j++)
        {
            if(mp[id][j].x==x) continue;
            dfs(d+1,mp[id][j].x,mp[id][j].y,x,y);
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)
    {
        mx=0;
        for(int i=1;i<=100000;i++) mp[i].clear();
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100000;j++) f[i][j]=0;
        }
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            s[i].clear();
            for(int j=0;j<l[i];j++)
            {
                int a;
                cin>>a;
                s[i].push_back(a);
                mp[a].push_back({i,j});
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r[i]>>c[i];
            mx=max(mx,r[i]);
        }
        int sz=mp[1].size();
        for(int i=0;i<sz;i++) dfs(1,mp[1][i].x,mp[1][i].y,0,0);
        for(int i=1;i<=q;i++) cout<<f[r[i]][c[i]]<<endl;
    }
    return 0;
}
