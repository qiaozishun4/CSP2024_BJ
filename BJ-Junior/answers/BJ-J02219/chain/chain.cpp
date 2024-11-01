/*
dp[i][j]=dp[i][k]&&isok(k,len);
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
int INF=0x3f3f3f3f;
int n,k,q,r,c;
int l,s[N][N];
bool dp[N][N];
bool ok(int f,int k,int len,int ned)
{
    for(int i=k; i<=n; i++)
    {
        if(i-k+1<=len&&s[f][i]==ned)
        {
            return true;
        }
    }
    return false;
}
void wok(int f,int r,int c)
{
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            for(int l=1; l<=k; l++)
            {
                if(dp[i-1][k]&&ok(f,l,k,j)||dp[i][j]==1){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=0;
                }
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(dp,0,sizeof dp);
        cin>>n>>k>>q;
        for(int i=1; i<=n; i++)
        {
            cin>>l;
            for(int j=1; j<=l; j++)
            {

                cin>>s[i][j];
                dp[1][s[i][j]]=1;
            }
        }
        for(int i=1; i<=q; i++)
        {
            cin>>r>>c;
            for(int j=1; j<=n; j++)
            {
                wok(j,r,c);
            }

            cout<<dp[r][c]<<'\n';
        }
    }
    return 0;
}
