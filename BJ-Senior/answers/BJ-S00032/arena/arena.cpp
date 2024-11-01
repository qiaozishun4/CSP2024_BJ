#include<bits/stdc++.h>
#define int long long
#define Pair pair<int,int>
using namespace std;
constexpr int N=2e5+5;
int n,m,K,sz;
struct game{
	int l,r,k;
	int val,pos;
	void init(int R,int cnt){
		l=(1<<R)*(cnt-1)+1,r=(1<<R)*cnt,k=R;
	}
};
vector<game> a[25];
int aa[N],c[N];
string d[25];
struct State{
	vector<Pair> kwn;//{val,pos}
	vector<Pair> unk;//{lp,rp}
	void Kwn(Pair x){
		vector<Pair>().swap(kwn);
		vector<Pair>().swap(unk);
		kwn.push_back(x);
	}
	void Unk(Pair x){
		vector<Pair>().swap(kwn);
		vector<Pair>().swap(unk);
		unk.push_back(x);
	}
	void Merge(State a,State b,char f,int base){
		if(f=='1') swap(a,b);
		bool flag=(!a.kwn.empty()&&a.kwn.back().first<base || !a.unk.empty());
		//whether b can contribute
		while(!a.kwn.empty()&&a.kwn.back().first<base) a.kwn.pop_back();
		if(!flag){
			swap(kwn,a.kwn); swap(unk,a.unk);
		}else{
			vector<Pair>().swap(kwn);
			vector<Pair>().swap(unk);
			for(auto x:a.unk) unk.push_back(x);
			for(auto x:b.unk) unk.push_back(x);
			//cout<<a.kwn.size()<<' '<<b.kwn.size()<<endl;
			int ptra=0,ptrb=0;
			while(!(ptra==a.kwn.size()&&ptrb==b.kwn.size())){
				if(ptra==a.kwn.size()) kwn.push_back(b.kwn[ptrb++]);
				else if(ptrb==b.kwn.size()) kwn.push_back(a.kwn[ptra++]);
				else{
					if(a.kwn[ptra].first>=b.kwn[ptrb].first) kwn.push_back(a.kwn[ptra++]);
					else kwn.push_back(a.kwn[ptra++]);
				}
			}
		}
	}
};
vector<State> S[25];
void Get(){
	int x[4]; cin>>x[0]>>x[1]>>x[2]>>x[3];
	for(int i=0;i<=K;i++) vector<game>().swap(a[i]);
	a[0].resize(sz+3);
	for(int i=1;i<=n;i++){
		a[0][i].init(0,i); a[0][i].val=(aa[i]^x[i%4]); a[0][i].pos=i;
	}
	for(int i=n+1;i<=sz;i++){
		a[0][i].init(0,i); a[0][i].val=0; a[0][i].pos=i;
	}
	for(int k=1;k<=K;k++){
		a[k].resize((sz>>k)+3);
		for(int i=1;i<=(sz>>k);i++){
			a[k][i].init(k,i);
			if(d[k][i]=='0'&&a[k-1][i*2-1].val>=k||d[k][i]=='1'&&a[k-1][i*2].val<k){
				a[k][i].val=a[k-1][i*2-1].val,a[k][i].pos=a[k-1][i*2-1].pos;
			}
			else{
				a[k][i].val=a[k-1][i*2].val,a[k][i].pos=a[k-1][i*2].pos;
			}
		}
	}
}
State query(int c,int k,int p){
	//cout<<c<<' '<<k<<' '<<p<<endl;
	State ans;
	if(a[k][p].r<=c){
		ans.Kwn({a[k][p].val,a[k][p].pos});
		return ans;
	}
	if(a[k][p].l>c){
		ans.Unk({a[k][p].l,a[k][p].r}); return ans;
	}
	ans.Merge(query(c,k-1,p*2-1),query(c,k-1,p*2),d[k][p],k);
	return ans;
}
int calc(int l,int r){
	return (l+r)*(r-l+1)/2;
}
int Query(int c){
	int k=(c==1?0:__lg(c-1)+1);
	State tmp=query(c,k,1);
	int ans=0;
	for(auto x:tmp.kwn) ans+=x.second;
	for(auto x:tmp.unk) ans+=calc(x.first,x.second);
	return ans;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin>>n>>m; K=(n==1?0:__lg(n-1)+1); sz=(1<<K);
    for(int i=1;i<=n;i++) cin>>aa[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=1;i<=K;i++) cin>>d[i],d[i]=' '+d[i];
    int T; cin>>T;
	for(int z=1;z<=T;z++){
		Get();
		int ans=0;
		for(int i=1;i<=m;i++) ans^=i*Query(c[i]);
		cout<<ans<<'\n';
	}
}
/*
g++ t3.cpp -o t2.exe -O2 -std=c++14 -fsanitize=undefined -Wall; ./t2.exe

g++ t3.cpp -o t3.exe -O2 -std=c++14; ./t3.exe

完了死了 空谷传响怎么坐我右前方。。
考场里人好像还挺多的 ljs lyx xxw syx shy lrq toka。




kotoshi no t1 to t2 ha honntoni yasashi desune.

凳子硬的我如坐针毡。

well, it seems not so bad since i finished t1&t2 in 80mins. T3ni muite, gannbarimasu!

打开了一个3.1MB的文件但是VScode没有崩溃!!!好的你是神机 你是分辨率不足1080p的神机（（

感觉像是在打一场时间极为宽裕的Div2。

啊啊啊啊啊啊完了t4大样例挂了 AK梦碎了
希望能得至少30pts（（
*/