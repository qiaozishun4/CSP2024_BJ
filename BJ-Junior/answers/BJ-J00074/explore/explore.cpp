#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x2,y2,d;
long long ans[15];
char ch[1005][1005];
int dfs(int a,int b)
{
    if(k==0)
    {
        sort(ans+1,ans+5);
        return ans[4];
    }

    if(ch[a-1][b]!='x')
    {


        if(d==0)
        {
            k-=3;
            d=3;
        }
        else if(d==1)
        {
            k-=2;
            d=3;
        }
        else if(d==2)
        {

            k--;
            d=3;
        }
        k--;
        ans[1]++;
        dfs(a-1,b);
    }
    else if(ch[a+1][b]!='x')
    {
        //d=1
        if(d==0)
        {
            k--;
            d=1;
        }
        else if(d==3)
        {
            k-=2;
            d=1;
        }
        else if(d==2)
        {
            k-=3;
            d=1;
        }

        k--;
        ans[2]++;
        dfs(a+1,b);
    }
    else if(ch[a][b-1]!='x')
    {

        if(d==1)
        {
            k--;
            d=2;
        }
        else if(d==0)
        {
            k-=2;
            d=2;
        }
        else if(d==3)
        {

            k-=3;
            d=2;
        }
        k--;
        ans[3]++;

        dfs(a,b-1);
    }
    else if(ch[a][b+1]!='x')
    {

        if(d==1)
        {
            k-=3;
            d=0;
        }
        else if(d==2)
        {
            k-=2;
            d=0;
        }
        else if(d==3)
        {
            k--;
            d=0;
        }
        k--;
        ans[4]++;

        dfs(a,b+1);
    }
    else return 1;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int l;
    cin>>n;
    while(n>0)
    {
        n--;
        cin>>n>>m>>k;
        cin>>x2>>y2>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>ch[i][j];
            }
        }
        l=dfs(x2,y2);
        cout<<l<<endl;

    }
    return 0;
}
