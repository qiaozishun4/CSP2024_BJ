#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n,m;
double L,V,d[N],v[N],a[N],p[N];
int cnt;
int ll;
bool f[N];
int t[N];
set<int> s[N];//记录每个第i个摄像头能记录到的车辆。
set<int> se;
bool find_camera(double FROM,double TO,int index){
	bool f=0;
	for(int i=1;i<=m;i++){
		if(FROM<p[i]&&p[i]<TO){
			s[i].insert(index);
			f=1;
		}
	}
	return f;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--){
		cnt=0;
		for(int i=1;i<=m;i++){
			s[i].clear();
		}
		se.clear();
		memset(f,0,sizeof f);
		cin >> n >> m >> L >> V;
		for(int i=1;i<=n;i++) cin >> d[i] >> v[i] >> a[i];
		for(int i=1;i<=m;i++) cin >> p[i];
		sort(p,p+m+1);
		for(int i=1;i<=n;i++){
			//判断是否会超速。

			// 1. 从开始就不超速，后面越来越慢/不变的；
			// 满足：(1) a[i] <= 0, (2)v[i] <= V.
			if(a[i]<=0&&v[i]<=V){
				continue;
			}

			// 2. 从开始就超速，后面越来越快/不变的；
			// 满足：(1) a[i] >= 0, (2)v[i] > V.
			// 即对于一切 p[i] > d[i] 的测速仪，都能检测到超速行为。
			else if(a[i]>=0&&v[i]>V){
				if(find_camera(d[i]-1,L+0.01,i))
					cnt++;
			}

			// 3. 一开始不超速，后面越来越快超了的；
			// 满足：(1) v[i] <= V, (2) v[i] * v[i] + 2 * a[i] * (L - d[i]) > V * V.
			// 超速的地点为 s = (V * V - v[i] * v[i]) / (2 * a) + d[i].
			// 即对于一切 p[i] > s 的测速仪，都能检测到超速行为。
			else if(a[i]>0&&v[i] <= V && v[i] * v[i] + 2 * a[i] * (L - d[i]) > V * V){
				if(find_camera((V * V - v[i] * v[i]) / (2 * a[i]) + d[i],L+0.01,i))
					cnt++;
			}

			// 4. 一开始不超速，后面越来越快也没超的；
			// 满足：(1) v[i] <= V, (2) v[i] * v[i] + 2 * a[i] * (L - d[i]) <= V * V.
			else if(a[i]>0&&v[i] <= V && v[i] * v[i] + 2 * a[i] * (L - d[i]) <= V * V){
				continue;
			}

			// 5. 一开始超速，后面越来越慢不超了的；
			// 满足：(1) v[i] >= V, (2) v[i] * v[i] + 2 * a[i] * (L - d[i]) <= V * V.
			// 超速的地点为 s = (V * V - v[i] * v[i]) / (2 * a) + d[i].
			// 即对于一切 p[i] < s 的测速仪，都能检测到超速行为。
			else if(a[i]<0&&v[i] >= V && v[i] * v[i] + 2 * a[i] * (L - d[i]) <= V * V){
				if(find_camera(d[i]-0.01,(V * V - v[i] * v[i]) / (2 * a[i]) + d[i],i))
					cnt++;
			}
			// 6. 一开始超速，后面越来越慢一直超的；
			// 满足：(1) v[i] >= V, (2) v[i] * v[i] + 2 * a[i] * (L - d[i]) > V * V.
			// 即对于一切 p[i] > d[i] 的测速仪，都能检测到超速行为。
			else if(a[i]<0&&v[i] >= V && v[i] * v[i] + 2 * a[i] * (L - d[i]) > V * V){
				if(find_camera(d[i]-0.01,L+1,i))
					cnt++;
			}
		}
		cout << cnt << " ";
		int i=1,u=1;
		int ans=0;
		while(se.size()!=cnt&&u<=m){
			int maxx=-1;
			for(int k=1;k<=m;k++){
				// cout <<f[k]<<" "<<s[k].size()<<" "<<k<<" "<<maxx<<endl;
				if(f[k]==0&&(int)s[k].size()>maxx){
					maxx=s[k].size();
					i=k;
					// cout <<"IIII";
				}
			}
			bool o=0;
			// cout <<endl<<i<<" ";
			for(auto it = s[i].begin();it!=s[i].end();it++){
				// cout <<*se.find(*it)<<" "<<*se.end()<<endl;
				if(se.find(*it)==se.end()||se.empty()){
					se.insert(*it);
					// for(int j=1;j<=m;j++){
					// 	if(se.empty()==0) continue;
					// 	if(s[j].find(*it)!=s[j].end())
					// 		s[j].erase(*it);
					// }
					o=1;
				}
			}
			f[i]=true;
			if(o) ans++;
			u++;
		}
		cout << m - ans<<endl;

	}
	return 0;
}