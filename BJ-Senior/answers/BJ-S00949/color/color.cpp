#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
const int C = 1e6+5;
int T;

int n,m;
int a[N];


struct node{
	int en,bllst;
	long long wt,prwt,prswt;
	friend bool operator<(node x,node y){
		return x.en < y.en;
	}
	friend bool operator==(node x,node y){
		return x.en == y.en;
	}
	node(int e,long long w,int v){
		en=e,wt=prwt=w,prswt=0,bllst=v;
	}
	node(int e,long long w,node pr,int v){
		en=e,wt=w,prwt=w+pr.prwt,prswt=pr.prswt,bllst=v;
	}
	node(int e,long long w,long long sw,node pr,int v){
		en=e,wt=w,prwt=w+pr.prwt,prswt=sw+pr.prswt,bllst=v;
	}
	node(){
		en=INT_MAX,wt=prwt=prswt=0,bllst=0;
	}
};

int dp[N][2];
int prv[N],cprv[C];
int pr_val[C];

#ifdef M_D
struct debug {
	vector<node> pushed;
	inline vector<node>::iterator begin(){
		return pushed.begin();
	}
	inline vector<node>::iterator end(){
		return pushed.end();
	}
	inline node back(){
		return pushed.back();
	}
	inline size_t size(){
		return pushed.size();
	}
	inline bool empty(){
		return pushed.empty();
	}
	inline void resize(size_t sz){
		cout << "\t\tResize: From " << pushed.size() << ", To " << sz << '\n' << flush;
		if(sz >= 1000000000000000005) return;
		pushed.resize(sz);
	}
	inline void push_back(node x){
		cout << "\t\tPush: { End:" << x.en << ", Weight:" << x.wt << "(Total " << x.prwt << '#' << x.prswt << "), BlueEnd:" << x.bllst << "}\n";
		pushed.push_back(x);
	}
	node operator[](int idx){
		return pushed[idx];
	}
	inline void clear(){
		pushed.clear();
	}
};
debug pushed;
#else
vector<node> pushed;
#endif

int main(){
	ios::sync_with_stdio(0);
	#ifndef M_D
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	#endif
	cin >> T;
	for(int Ti = 1;Ti <= T;++Ti){
		#ifdef M_D
		cout << "Sam " << Ti << " :\n";
		#endif
		memset(cprv,0,sizeof(cprv));
		pushed.clear();

		cin >> n;
		for(int i = 1;i <= n;++i){
			cin >> a[i];
			prv[i]=cprv[a[i]];
			cprv[a[i]]=i;
		}
		for(int i = 1;i <= n;++i){
			#ifdef M_D
			cout << "\tNumber " << i << " :\n";
			#endif
			if(prv[i]){
				#ifdef M_D
				cout << "\t\t\e[31mCheck: From " << prv[i] << " to " << i << "(Val=" << a[i] << ") !\e[39m\n";
				#endif
				if(pushed.empty()){
					pushed.push_back(node(prv[i],a[i],node(),a[i-1]));
					continue;
				} else {
					long long sum = 0;
					int idx = lower_bound(pushed.begin(),pushed.end(),node(prv[i],0,0)) - pushed.begin();
					if(idx < pushed.size()){
						sum=pushed.back().prwt;//#+pushed.back().prswt;
						#ifdef M_D
						cout << "\t\tSum: " << sum << '\n';
						#endif
						if(idx>0) sum -= pushed[idx-1].prwt;//#+pushed.back().prswt;
						#ifdef M_D
						cout << "\t\tSum: " << sum << '\n';
						#endif
					}
					int clr = idx==0 ? 0 : ( pushed[idx-1].bllst==a[i-1] && prv[i] < i-1? a[i-1] : 0 );
					long long curw = 0,cursw = pushed.back().prswt;
					if(idx>0) cursw-=pushed[idx-1].prswt;
					if(prv[i]>=i-1){
						cursw+=a[i];
					} else {
						curw+=a[i];
					}
					if(idx > 0) curw -= pushed[idx].prswt;
					if(clr == 0 && prv[i] < i-1) clr=pushed.back().bllst;
					#ifdef M_D
					cout << "\t\t\e[31mChecked: From " << prv[i] << " to " << i << " : " << curw << '#' << cursw << " VS " << sum << " !\e[39m\n";
					#endif
					#ifdef M_D
					cout << "\t\tIdx: " << idx << ", " << pushed.back().prswt << '-' << pushed[idx-1].prswt << " !\n";
					#endif
					if(a[i] >= sum){
						pushed.resize(max(0,idx-1));
						pushed.push_back(node(prv[i],curw,cursw,idx?pushed[idx-1]:node(),clr));
					} else if( pushed.back().bllst == a[i] ) {
						pushed.push_back(node(i,a[i],idx?pushed[idx-1]:node(),a[i]));
					}
				}
			}
		}
		#ifdef M_D
		cout << "\t\e[33mResult: \e[39m";
		#endif
		if(pushed.empty()){
			cout << "0\n";
		} else {
			cout << pushed.back().prwt+pushed.back().prswt << '\n';
		}
	}
	
	return 0;
}