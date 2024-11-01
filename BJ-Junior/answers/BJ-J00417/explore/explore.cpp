#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x0,y,d0,cnt,nu=0;
string s[100000];
bool aa[10000][1000];
void dfs(long long a,long long b,long long c)
{
    //cout<<"dfs,x="<<a<<",y="<<b<<",fangxiang="<<c<<","<<"caozuo"<<nu<<endl;

    //for(int i=1;i<=2000000000;i++)
    //for(int i=1;i<=5000000000;i++)


    if(nu==k)return ;
    nu++;
    long long d,e;
    if(c==0){
        d=a;
        e=b+1;
    }
    else if(c==1)
    {
        d=a+1;
        e=b;
    }
    else if(c==2)
    {
        d=a;
        e=b-1;
    }
    else if(c==3)
    {
        d=a-1;
        e=b;
    }
    //cout<<"weizhi,x="<<d<<",y="<<e<<endl;



    //for(int i=1;i<=2000000000;i++)



    if(d>=1&&e>=1&&d<=n&&e<=m&&s[d][e-1]=='.')
    {
        //cout<<"yes"<<endl;
        if(aa[a][b]==0)
        {
            //cout<<a<<","<<b<<"+1"<<endl;
            cnt++;
        }
        //else cout<<a<<","<<b<<"beibiaojiguole"<<endl;
        if(aa[d][e]==0)
        {
            //cout<<d<<","<<e<<"+1"<<endl;
            cnt++;
        }
        //else cout<<d<<","<<e<<"beibiaojiguole"<<endl;
        aa[a][b]=1;
        aa[d][e]=1;
        dfs(d,e,c);
    }
    else
    {
        //cout<<"no"<<endl;
        long long  f=(c+1)%4;
        //cout<<"f="<<f<<endl;

        dfs(a,b,f);
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x0>>y>>d0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        //cout<<"dfskaishi"<<endl;
        aa[x0][y]=1;
        cnt++;
        dfs(x0,y,d0);
        cout<<cnt<<endl;

        nu=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                aa[i][j]=0;
            }
        }
    }
    return 0;
}