#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, L = 1e6+5;
int n, m, l, V;
int d[N], v[N], a[N], p[N];
int nxt[L], pre[L];
int lst[N];
bool mark[N];
vector<int> exc;
stack<int> sta;

struct Segment{
	int l, r;
}seg[N];
int New[N];

bool cmp(Segment a, Segment b){
	if(a.l==b.l) return a.r>b.r;
	return a.l<b.l;
}

inline bool isexc(int i){
	if(nxt[d[i]]==-1) return 0;
	if(a[i]>=0){
		int s = p[m]-d[i];
		if(v[i]*v[i]+2*a[i]*s>V*V) return 1;
		return 0;
	}
	else{
		int s = p[nxt[d[i]]]-d[i];
		if(v[i]*v[i]+2*a[i]*s>V*V) return 1;
		return 0;
	}
	return 0;
}

int main(){
	const bool debug = 0;
	ios::sync_with_stdio(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	int T;
	
	cin >> T;
	while(T--){
		bool Task1 = 1;
		exc.clear();
		memset(mark, 0, sizeof(mark));
		memset(seg, 0, sizeof(seg));
//		memset(pre, 0, sizeof(pre));
//		memset(nxt, 0, sizeof(nxt));
		cin >> n >> m >> l >> V;
//		if(T==2) cout << m << endl;
		for(int i=1;i<=n;i++){
			cin >> d[i] >> v[i] >> a[i];
			if(a[i]<0) Task1 = 0;
		}
		for(int i=1;i<=m;i++){
			cin >> p[i];
		}
		p[0] = -1, p[m+1] = l+1;
		for(int j=p[m]+1;j<=l;j++) nxt[j] = -1;
		for(int i=m;i>=1;i--){
			for(int j=p[i-1]+1;j<=p[i];j++){
				nxt[j] = i;
			}
		}
		for(int j=0;j<p[1];j++) pre[j] = -1;
		for(int i=1;i<=m;i++){
			for(int j=p[i];j<p[i+1];j++){
				pre[j] = i;
			}
		}
//		for(int j=0;j<l;j++) cout << pre[j] << endl;
		int ans1 = 0;
		for(int i=1;i<=n;i++){
			if(isexc(i)){
				ans1++;
				exc.push_back(i);
			}
		}
		cout << ans1 << ' ';
//		if(T==4) cout << "hear" << endl;
		
		if(Task1 && !debug){
			if(ans1) cout << m-1;
			else cout << m;
		}
		else{
			int tot = exc.size();
//			if(T==4) cout << tot << endl;
//			for(int i=0;i<tot;i++) cout << exc[i] << endl;
			for(int i=0;i<tot;i++){
				int j = exc[i];
				if(a[j]==0){
					seg[i+1].l = nxt[d[j]], seg[i+1].r = m;
				}
				else if(a[j]>0){
					double x = (V*V-v[j]*v[j])/(2.0*a[j]);
					if(x<0) x = 0;
					int u = ceil(x+d[j]);
					seg[i+1].l = nxt[u], seg[i+1].r = m;
				}
				else{
					double x = (v[j]*v[j]-V*V)/(2.0*(-a[j]));
					int u = x+d[j];
					if(u>l) u = l;
					seg[i+1].l = nxt[d[j]], seg[i+1].r = pre[u];
//					cout << seg[i+1].r << endl;
				}
			}
//			if(T==4) cout << "hear" << endl;
//			for(int i=1;i<=tot;i++) cout << seg[i].l << ' ' << seg[i].r << endl;
			sort(seg+1, seg+tot+1, cmp);
			
//			cout << "hear" << endl;
			
			for(int i=1;i<=tot;i++){
				lst[i] = i-1;
			}
			for(int i=2;i<=tot;i++){
				if(seg[i].r<=seg[lst[i]].r){
					int t = lst[i];
					while(t && seg[t].r>=seg[i].r){
						mark[t] = 1;
						lst[i] = lst[t];
						t = lst[t];
					}
				}
			}
//			cout << "hear" << endl;
			
//			for(int i=1;i<=tot;i++) cout << lst[i] << endl;
			
			for(int i=tot;i;i=lst[i]){
				sta.push(i);
			}
//			cout << "hear" << endl;
			tot = 0;
			while(!sta.empty()){
				New[++tot] = sta.top(); sta.pop();
			}
			int rm = 0, ans = 0;
			for(int i=1;i<=tot;i++){
				if(seg[New[i]].l>rm){
					ans++;
					rm = seg[New[i]].r;
				}
			}
			
			cout << m-ans;
		}
		cout << endl;
	}
	
	return 0;
}
