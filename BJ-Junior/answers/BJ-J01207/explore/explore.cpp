#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int sum=1,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},n,m,flag;
bool number_flag[1005][1005];
void dfs(int x,int y,int d,int k)
{
    if (k==0)
    {
        flag=1;
        return ;
    }
    if (flag==1) return ;
    int next_x=x+dx[d],next_y=y+dy[d];
    k--;
    if (s[next_x][next_y]=='.')
    {
        if (number_flag[next_x][next_y]==0) sum++,number_flag[next_x][next_y]=1;
        dfs(next_x,next_y,d,k);
    }
    else dfs(x,y,(d+1)%4,k);
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,k,start_x,start_y,d;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>k>>start_x>>start_y>>d;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin>>s[i][j];
        dfs(start_x,start_y,d,k);
        cout<<sum<<endl;
        sum=1,flag=0;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) s[i][j]=' ',number_flag[i][j]=0;
    }
    return 0;
}
