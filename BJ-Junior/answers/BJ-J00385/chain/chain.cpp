#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2000+5;
int l[N];
int s[M][M*2];
int n,r,c;
int k;
int flag;
void dfs(int cur,int last,int pos)
{
    if(flag) return ;
    if(cur>r)
    {
        if(last==c)
        {
            flag=1;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=l[i];j++)
        {
            if(s[i][j]==last && i!=pos)
            {
                for(int p=2;p<=k;p++)
                {
                    dfs(cur+1,s[i][j+p-1],i);
                }
            }
        }
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int q;
        cin >>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin >>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin >>s[i][j];
            }
        }
        while(q--)
        {
            cin >>r>>c;
            dfs(1,1,0);
            cout <<flag<<'\n';
            flag=0;
        }
    }
    return 0;
}
