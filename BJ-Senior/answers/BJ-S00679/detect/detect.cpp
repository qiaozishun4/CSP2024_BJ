#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define uint unsigned
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define pb push_back
#define SZ(x) ((int)x.size())
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
using namespace std;
void fre(){
	freopen("detect.in","r",stdin),freopen("detect.out","w",stdout);
}
inline void chkmax(int &x,int y){ x=std::max(x,y); }
inline void chkmin(int &x,int y){ x=std::min(x,y); }
const int maxn=100005;
const double eps=1e-7;
int ca[maxn],cv[maxn],cd[maxn],a[maxn],n,m,L,k,cl[maxn],cr[maxn],flag[maxn],tag[maxn];
vector<int>qaq[maxn];
int t[maxn];
void add(int x,int y=1){ for(;x<=m;x+=lowbit(x))t[x]+=y; }
int query(int x){ int res=0; for(;x;x^=lowbit(x))res+=t[x]; return res; }
void SOlvE(){
	cin>>n>>m>>L>>k;
	F(i,1,n)cin>>cd[i]>>cv[i]>>ca[i],flag[i]=0;
	F(i,1,m)cin>>a[i],qaq[i].clear(),t[i]=0;
	int ans1=0;
	F(i,1,n){
		if(a[m]<cd[i])continue;
		if(ca[i]>0){
			int l=lower_bound(a+1,a+m+1,cd[i])-a,r=m,pos=0;
			while(l<=r){
				int mid=(l+r)>>1;
				double v=sqrt(1.0*cv[i]*cv[i]+2.0*ca[i]*(a[mid]-cd[i]));
				if(v>k&&fabs(v-1.0*k)>eps)pos=mid,r=mid-1;
				else l=mid+1;
			}
			if(!pos)continue;
			flag[i]=1;
			cl[i]=pos,cr[i]=m;
		}else if(ca[i]==0){
			if(cv[i]<=k)continue;
			int pos=lower_bound(a+1,a+m+1,cd[i])-a;
			cl[i]=pos,cr[i]=m;
			flag[i]=1;
		}else{
			int l=lower_bound(a+1,a+m+1,cd[i])-a,r=m,pos=0,qwq=l;
			while(l<=r){
				int mid=(l+r)>>1;
				double v=sqrt(1.0*cv[i]*cv[i]+2.0*ca[i]*(a[mid]-cd[i]));
				if(v>k&&fabs(v-1.0*k)>eps)pos=mid,l=mid+1;
				else r=mid-1;
			}
			if(!pos)continue;
			flag[i]=1;
			cl[i]=qwq,cr[i]=pos;
		}
		if(cl[i]>cr[i])flag[i]=0;
	}
	F(i,1,n)if(flag[i])++ans1;
	vector<pii>vec,lmx;
	F(i,1,n)if(flag[i])vec.push_back(mkp(cl[i],cr[i]));
	F(i,0,SZ(vec)-1){
		tag[i]=0;
		const int l=vec[i].fi;
		qaq[l].push_back(i);
	}
	dF(i,m,1)if(!qaq[i].empty()){
		const int tmp=SZ(qaq[i]);
		sort(qaq[i].begin(),qaq[i].end(),[&](int x,int y){ return vec[x].se<vec[y].se; });
		F(j,0,tmp-1){
			const int id=qaq[i][j];
			if(query(vec[id].se))tag[id]=1;
			else add(vec[id].se);
		}
	}
	F(i,0,SZ(vec)-1)if(!tag[i])lmx.push_back(mkp(vec[i].fi,vec[i].se));
	sort(lmx.begin(),lmx.end());
	int ans2=0;
	const int siz=SZ(lmx);
	F(i,0,siz-1){
		++ans2;
		const int r=lmx[i].se;
		for(;i+1<siz&&lmx[i+1].first<=r;++i);
	}
	cout<<ans1<<' '<<(m-ans2)<<endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fre();
	int multi=1; cin>>multi;
	F(_,1,multi)SOlvE();
}
// g++ detect.cpp -o a -std=c++14 -O2 -fsanitize=undefined,address -Wall -Wextra