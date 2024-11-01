#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=1e5+233,M=2e5+233;
int n,K,m;
vector<int> a[N];
int s[2][M],dp[2][M];
int L[N],R[N],pos[M],b[M];
vector<pii> q[114];
int ans[N];
inline void _main()
{
    cin>>n>>K>>m;
    for (int i=1;i<=n;i++)
    {
        int l,x;
        scanf("%d",&l);
        while (l--) scanf("%d",&x),a[i].pb(x);
        L[i]=R[i-1]+1,R[i]=L[i]+a[i].size()-1;
        for (int j=L[i];j<=R[i];j++) pos[j]=i,b[j]=a[i][j-L[i]];
    }
    int mxr=0;
    for (int i=1;i<=m;i++)
    {
        int r,c;
        scanf("%d%d",&r,&c);
        q[r].pb({c,i});
        mxr=max(mxr,r);
    }
    if (1ll*R[n]*K*100>1e9)
    {
		for (int i=1;i<=m;i++)
			cout<<0<<endl;
	}
	else
	{
		for (int i=1;i<=R[n];i++)
			dp[0][i]=1,s[0][b[i]]++;
		for (int r=1;r<=mxr;r++)
		{
			for (int i=0;i<M;i++) s[r&1][i]=0;
			for (int i=1;i<=R[n];i++)
			{
				dp[r&1][i]=0;
				for (int j=i-1;pos[j]==pos[i]&&i-j+1<=K;j--)
					dp[r&1][i]|=s[(r&1)^1][b[j]]>dp[(r&1)^1][j];
				s[r&1][b[i]]+=dp[r&1][i];
			}
			for (auto u:q[r])
				ans[u.second]=s[r&1][u.first]>0;
		}
		for (int i=1;i<=m;i++)
			cout<<ans[i]<<endl;
		for (int i=1;i<=n;i++) a[i].clear();
		for (int i=1;i<=100;i++) q[i].clear();
		memset(ans,0,sizeof ans);
		memset(L,0,sizeof L),memset(R,0,sizeof R);
		memset(pos,0,sizeof pos),memset(b,0,sizeof b);
		memset(s,0,sizeof s),memset(dp,0,sizeof dp);
	}
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    for (cin>>t;t;t--) _main();

    return 0;
}
//orz to nzhtl1477
//rp<<=114514
