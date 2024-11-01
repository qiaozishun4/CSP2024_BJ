// 会赢吗？
//15:10 D hao nan

//15:59 huile ma? O(T(m)logn)
//16:25 start debugging
// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b,c)    for(int i=(a),i##end=(b);i<=(i##end);i+=(c))
#define per(i,a,b,c)    for(int i=(a),i##end=(b);i>=(i##end);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define vint vector<int>
#define _1 first
#define _2 second
using namespace std;
bool Mbe;

const int maxn=2.02e5;
const int inf=LLONG_MAX;
int aa[maxn],b[maxn],a[maxn];
int c[maxn];
vector<bool> R[20];
vector<signed> org[20];
/*
org: a
man:inf&0
*/
inline int su(int l,int r){
	return r*(r+1)/2-l*(l-1)/2;
}
struct Node{
	vint a;
	int s;
	Node(){
		s=0;
	}
}retg;

int mi=inf;
void get(int x,int k,int i,int l,int r){		//[1,x],now at (k,l,r)
auto cmp=[&](int x,int y){
	return a[x]>a[y];
};
	if(!k){
		retg.s=0;
		mi=inf;
		retg.a.clear();
		if(i<=x)    retg.a.pb(i),mi=a[i];
		else        retg.s+=i;
		
		return ; 
	}
	int mid=(l+r)/2;
	if(R[k][i]){
		if(x<=mid){
			get(x,k-1,i*2-1,l,mid);
			retg.s+=su(mid+1,r);
			return ;
		}else{
			int p=org[k-1][i*2-1];
			get(x,k-1,i*2,mid+1,r);
			bool flg=retg.s;
			if(mi<k){
				flg=1;
				sort(retg.a.begin(),retg.a.end(),cmp);
				int p=retg.a.size();
				rep(i,0,retg.a.size()-1,1){
					if(a[retg.a[i]]<k){
						p=i;
						break ;
					}
				}
				retg.a.erase(retg.a.begin()+p,retg.a.end());
				if(!retg.a.empty())	mi=a[retg.a.back()];
				else				mi=inf;
			}
			if(flg)	retg.a.pb(p),mi=min(mi,a[p]);
			return ;
		}
	}
	else{
		//always 1
		if(x<mid){
			get(x,k-1,i*2-1,l,mid);
			bool flg=retg.s;
			if(mi<k){
				// cerr<<retg.a.size()<<" "<<retg.a[0]<<" "<<retg.a[1]<<" "<<retg.a[2]<<" "<<mi<<endl;

				flg=1;
				sort(retg.a.begin(),retg.a.end(),cmp);
				int p=retg.a.size();
				rep(i,0,retg.a.size()-1,1){
					if(a[retg.a[i]]<k){
						p=i;
						break ;
					}
				}
				retg.a.erase(retg.a.begin()+p,retg.a.end());
				if(!retg.a.empty())	mi=a[retg.a.back()];
				else				mi=inf;
			}	
			if(flg)	retg.s+=su(mid+1,r);
			return ;
		}else{
			int p=org[k-1][i*2-1];
			if(a[p]>=k){	
				retg.s=0,retg.a.clear();
				mi=a[p];
				retg.a.pb(p);
				return ;
			}
			get(x,k-1,i*2,mid+1,r);
			return ;
		}
	}
}
int lg[maxn];

bool Med;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	// int T;cin>>T;
	// while(T--)  solve();
	int n,m;cin>>n>>m;
	rep(i,1,n,1){
		if((1<<lg[i-1])>=i)	lg[i]=lg[i-1];
		else				lg[i]=lg[i-1]+1;
	}
	rep(i,1,n,1)	cin>>aa[i];
	rep(i,1,m,1)	cin>>c[i];
	int k=lg[n];
	rep(i,1,k,1){
		R[i].resize((1<<(k-i))+10);
		org[i].resize((1<<(k-i))+10);
		char ch;
		rep(j,1,1<<(k-i),1)	cin>>ch,R[i][j]=ch-'0';
	}
	int T;cin>>T;
	org[0].resize((1<<k)+10);
		// cerr<<T<<endl;
	while(T--){
		{
			int x[4];cin>>x[0]>>x[1]>>x[2]>>x[3];
			rep(i,1,n,1)	a[i]=aa[i]^x[i&3],a[i]=min(a[i],19ll);
		}
		rep(i,1,n,1)	org[0][i]=i;
		rep(i,1,k,1)	rep(j,1,1<<(k-i),1){
			if(R[i][j]){
				if(a[org[i-1][j*2]]>=i)		org[i][j]=org[i-1][j*2];
				else						org[i][j]=org[i-1][j*2-1];
			}else{
				if(a[org[i-1][j*2-1]]>=i)	org[i][j]=org[i-1][j*2-1];
				else						org[i][j]=org[i-1][j*2];
			}
		}
		//above:O(n)
		int out=0;
		rep(_,1,m,1){
			int x=c[_];
			// x=5;
			mi=inf;
			retg.s=0;
			retg.a.clear();
			get(x,lg[x],1,1,(1<<lg[x]));
			int su=0;
			for(auto p:retg.a)	if(p>0)	su+=p;
			su+=retg.s;
			out^=_*(su);
		}
		cout<<out<<'\n';
	}
	return 0;
}