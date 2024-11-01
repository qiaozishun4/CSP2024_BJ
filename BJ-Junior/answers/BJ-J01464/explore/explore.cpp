#include<bits/stdc++.h>
using namespace std;
short dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool g[1024][1024];
int main(void)
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    for(cin>>T;T;T--)
    {
        memset(g,false,sizeof(g));
        int n,m,k,x,y,d;
        set<pair<int,int>> st;
        cin>>n>>m>>k>>x>>y>>d;
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)g[i][j]=(getchar()=='.');
            getchar();
        }
        for(st.insert({x,y});k--;st.insert({x,y}))g[x+dx[d]][y+dy[d]]?x+=dx[d],y+=dy[d]:d=(d+1)%4;
        cout<<st.size()<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
