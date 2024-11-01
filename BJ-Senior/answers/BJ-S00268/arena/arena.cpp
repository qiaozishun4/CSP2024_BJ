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
int a[MAXN]; int k; int n;
void UUm(pii &rt,pii tp) { Umx(rt.fi,tp.fi);Umx(rt.se,tp.se); }
	#define ls i*2 
	#define rs i*2+1
	struct meow { ll mx;int tg; } tr[2][1000001*4];
	void pd(int i) { For(j,0,1){if(tr[j][i].tg){int tp=tr[j][i].tg;tr[j][ls].mx+=tp;tr[j][rs].mx+=tp;tr[j][i].tg=0;tr[j][ls].tg+=tp;tr[j][rs].tg+=tp;}}return ; }
	void pu(int i) { For(j,0,1)tr[j][i].mx=max(tr[j][ls].mx,tr[j][rs].mx); return ; }
	void build(int i,int l,int r) {tr[0][i].tg=0;tr[1][i].tg=0;tr[0][i].mx=tr[1][i].mx=-INF;if(l==r){if(r==0){tr[0][i].mx=tr[1][i].mx=0;}else {tr[0][i].mx=-INF;tr[1][i].mx=-INF;}return ;}int mid=(l+r)/2; build(ls,l,mid);build(rs,mid+1,r);pu(i);return ; }
	void add_a(int vl) { tr[0][1].tg+=vl;tr[1][1].tg+=vl;tr[0][1].mx+=vl;tr[1][1].mx+=vl; return ; }
	void Cmx(int i,int l,int r,int p,int vl1,int vl2)
	{
		if(l==r) { Umx(tr[0][i].mx,vl1);Umx(tr[1][i].mx,vl2); return ; } pd(i);
		int mid=(l+r)/2; if(mid>=p)Cmx(ls,l,mid,p,vl1,vl2);
		else Cmx(rs,mid+1,r,p,vl1,vl2); pu(i); return ;
	}
	pii Qmx(int i,int l,int r,int tl,int tt)
	{pii rt=make_pair(-INF,-INF);
		if(l<=tl&&r>=tt) { pii tp=make_pair(tr[0][i].mx,tr[1][i].mx); return tp; } 
		pd(i);
		int mid=(l+r)/2;if(mid>=tl) { pii tp=Qmx(ls,l,mid,tl,tt); UUm(rt,tp); }
		else { pii tp=Qmx(rs,mid+1,r,tl,tt); UUm(rt,tp); }
		pu(i); return rt;
	}
 main()
{
	freopen("color1.in","r",stdin);
	//freopen("color.out","w",stdout);
	int _; cin>>_;For(__,1,_)
	{
		int np=0;
		k=0; cin>>n; For(i,1,n) { cin>>a[i];Umx(k,a[i]); }a[0]=0;++k;
		build(1,0,k); For(i,0,15) { cerr<<tr[0][i].mx<<" "
<<tr[1][k].mx<<"\n"; } WR("\n");
		//dp[1][0][0]=dp[1][0][1]=0;
		int ls1=-INF,ls2=-INF;
		For(i,1,n) { 
		cerr<<ls1<<" "<<ls2<<"qwq\n";
			if(a[i-1]==a[i]) { add_a(a[i]); }
				//Umx(dp[np][j][0],dp[np^1][j][0]+(a[i-1]==a[i])*a[i]);
				//Umx(dp[np][j][1],dp[np^1][j][1]+(a[i-1]==a[i])*a[i]);
				//cerr<<"dp_{"<<i<<","<<j<<"}="<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\n";	
			Cmx(1,0,k,a[i-1],ls1,ls2);
			
			if(i!=n)
			{	pii rt1=make_pair(-INF,-INF);
				UUm(rt1,Qmx(1,0,k,0,a[i+1]-1)); UUm(rt1,Qmx(1,0,k,a[i+1]+1,k));
				pii tp2=Qmx(1,0,k,a[i+1],a[i+1]); tp2.fi+=a[i+1]; tp2.se+=a[i+1];
				UUm(rt1,tp2);
				ls2=rt1.fi;ls1=rt1.se;
			}
			/*For(t,0,k) {
				Umx(dp[np][a[i-1]][0],dp[np^1][t][1]+(t==a[i])*a[i]);
				Umx(dp[np][a[i-1]][1],dp[np^1][t][0]+(t==a[i])*a[i]);
			}*/
		 } 
		pii tp=Qmx(1,0,k,0,k); int ans=max(tp.fi,tp.se);
		//int ans=0; For(j,1,k) Umx(ans,max(dp[np][j][0],dp[np][j][1]));
		cout<<ans<<"\n";
	}
	return 0;
}