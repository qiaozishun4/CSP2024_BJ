#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int T,n,k,q,r,c,l;
bool flag;
int s[10005][20005];
void dfs(int i,int r)
{
    if(r<=0)
    {
        return ;
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while(T)
    {
        memset(s,0,sizeof(s));
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++)
        {
            cin >> l;
            for(int j=1;j<=l;j++)
            {
                cin >> s[i][j];
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin >> r >> c;
            flag=false;
            for(int i=1;i<=n;i++)
            {
                dfs(i,r);
            }
            cout << flag;
        }
        T--;
    }
    return 0;
}
