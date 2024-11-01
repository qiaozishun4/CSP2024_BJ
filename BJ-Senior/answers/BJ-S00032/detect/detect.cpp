#include<bits/stdc++.h>
#define int long long
#define double long double
#define Pair pair<int,int>
using namespace std;
constexpr int N=1e5+5;
int n,m,L,V;
double _=1,eps=1e-9;
vector<double> pos;
int leq(double x){
	return upper_bound(pos.begin(),pos.end(),x)-pos.begin()-1;
}
int geq(double x){
	return lower_bound(pos.begin(),pos.end(),x)-pos.begin();
}
struct car{
    int d,v,a;
    double Lpos,Rpos;
    int lp,rp;
	void calc(){
		if(a==0) Lpos=(v>V)?d:L,Rpos=(v>V)?L:0;
		else if(a>0){
			double pos=((double)(1)*V*V-v*v)/(2*a);
			Lpos=max(d*_,d+pos+eps); Rpos=L;
		}else{
			double pos=((double)(1)*V*V-v*v)/(2*a);
			Lpos=d; Rpos=min(L*_,d+pos-eps);
		}
		//cout<<Lpos<<" - "<<Rpos<<endl;
		lp=geq(Lpos); rp=leq(Rpos);
		//cout<<lp<<' '<<rp<<endl;
	}
}a[N];
struct Rng{
	int l,r;
	bool operator<(Rng t){
		return (r==t.r?l>t.l:r<t.r);
	}
};
vector<Rng> range;
int f[N];
void Solve(){
	cout<<range.size()<<' ';
	sort(range.begin(),range.end());
	int lst=0,ptr=0;
	for(auto x:range){
		//cout<<x.l<<' '<<x.r<<endl;
		while(ptr!=x.r){
			ptr++; f[ptr]=f[ptr-1];
		}
		if(x.l<=lst) continue;
		else lst=x.l;
		f[x.r]=f[x.l-1]+1;
	}
	cout<<m-f[ptr]<<'\n';
}
void init(){
	vector<double>().swap(pos);
	vector<Rng>().swap(range);
	for(int i=0;i<=m;i++) f[i]=0;
}
signed main(){
    freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    for(int z=1;z<=T;z++){
        cin>>n>>m>>L>>V;
		init();
        for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].a;
		for(int i=1;i<=m;i++){
			int t; cin>>t; pos.push_back(t);
		}
		sort(pos.begin(),pos.end());
		for(int i=1;i<=n;i++){
			a[i].calc();
			if(a[i].lp<=a[i].rp) range.push_back({a[i].lp+1,a[i].rp+1});
		}
		Solve();
    }
}