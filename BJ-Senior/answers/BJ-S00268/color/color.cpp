#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define int long long
#define ull unsigned long long 
#define pii pair<int,int>
#define pk pop_back
#define pb push_back
#define fi first
#define se second
#define ll long long
#define WA cerr<<"meowww~\n";
#define WR(x) cerr<<x<<"\n";
#define C continue
#define pii pair<int,int>
#define INF 1e17
//const int MOD=
#define MAXN 200001
void Umn(int &x,int y) { if(x>y)x=y;return ; }
void Umx(int &x,int y) { if(x<y)x=y;return ; }
//void MD(int &x) { if(x<0)x+=MOD;if(x>MOD)x-=MOD;return ; }
int dp[2][1000001][2]; int a[MAXN]; int k; int n;
 main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int _; cin>>_;For(__,1,_)
	{
		int np=0;
		k=0; cin>>n; For(i,1,n) { cin>>a[i];Umx(k,a[i]); }a[0]=0;
		For(j,0,k) For(o,0,1) dp[o][j][0]=dp[o][j][1]=-INF;
		//dp[1][0][0]=dp[1][0][1]=0;
		dp[0][0][0]=dp[0][0][1]=0;
		For(i,1,n) { 
			np^=1;
			For(t,0,k) {
				Umx(dp[np][a[i-1]][0],dp[np^1][t][1]+(t==a[i])*a[i]);
				Umx(dp[np][a[i-1]][1],dp[np^1][t][0]+(t==a[i])*a[i]);
			}
			For(j,1,k) 
			{
				Umx(dp[np][j][0],dp[np^1][j][0]+(a[i-1]==a[i])*a[i]);
				Umx(dp[np][j][1],dp[np^1][j][1]+(a[i-1]==a[i])*a[i]);
				//cerr<<"dp_{"<<i<<","<<j<<"}="<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\n";
			}
		 } 
		int ans=0; For(j,1,k) Umx(ans,max(dp[np][j][0],dp[np][j][1]));
		cout<<ans<<"\n";
	}
	return 0;
}