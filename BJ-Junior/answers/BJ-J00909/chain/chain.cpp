#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int T;
int n,k,q;
int l[N],S[1001][N],r[N],c[N];
int vis[1001][N];
bool flag=false;
void dfs(int cnt,int I,int lst,int lo)
{
    if(!cnt)
    {
        if(!flag&&lst==1)
        {
            flag=true;
            cout<<"1"<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=l[i];j++)
        {
            if(cnt==r[I])
            {
                if(S[i][j]==c[I])
                {
                    for(int o=j-1;o>=j-k+1&&o>=1;o--)
                    {
                        if(j-o+1>=2)
                        {
                            //cout<<i<<" "<<o<<" "<<j<<endl;
                            dfs(cnt-1,I,S[i][o],i);
                        }
                    }
                }
            }
            else
            {
                if(S[i][j]==lst)
                {
                    for(int o=j-1;o>=j-k+1&&o>=1;o--)
                    {
                        if(j-o+1>=2&&lo!=i)
                        {
                            //cout<<i<<" "<<o<<" "<<j<<endl;
                            dfs(cnt-1,I,S[i][o],i);
                        }
                    }
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> q;
        for(int i=1;i<=n;i++)
        {
            cin >> l[i];
            for(int j=1;j<=l[i];j++)cin >> S[i][j];
        }
        for(int i=1;i<=q;i++)cin >> r[i] >> c[i];
        for(int i=1;i<=q;i++)
        {
            flag=false;
            dfs(r[i],i,0,0);
            if(!flag)cout<<"0"<<endl;
        }
    }
    return 0;
}