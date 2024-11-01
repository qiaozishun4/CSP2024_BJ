#include<iostream>
#include<string>
using namespace std;
string str[10001];
int book[1001][10001];
int nt[5][3]={{0,1},{1,0},{0,-1},{-1,0}};
int dfs(int n,int m,int k,int x,int y,int step,int tmp)
{
    if(step==k)
    {
        int mio=0;
        return max(mio,tmp);
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+nt[0][i],dy=y+nt[1][i];
        if(dx<1||dy<1||dx>n||dy>m)
        {
            continue;
        }
        else if(book[dx][dy]==1||str[dx][dy]=='x')
        {
            continue;
        }
        else
        {
            book[dx][dy]=1;
            tmp=dfs(n,m,k,dx,dy,step+1,tmp+1);
            book[dx][dy]=0;
        }
    }
    return tmp;
}
int main()
{
freopen("exploer.in","r",stdin);
freopen("exploer.out","w",stdout);
    int t,io=0;
    cin>>t;
    while(t--)
    {
        int n,m,k,x0,y0,d0;
        cin>>n>>m>>k>>x0>>y0>>d0;
        for(int i=1;i<=n;i++)
        {
            cin>>str[i];
        }
        dfs(n,m,k,x0,y0,0,io);
        cout<<io;
    }
    return 0;
}