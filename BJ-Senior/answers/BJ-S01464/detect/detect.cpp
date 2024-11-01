#include <bits/stdc++.h>
using namespace std;
int T, n, m, l, v, d[100002], u[100002], a[100002], p[100002], cnt[100002], ans1, ans2;
vector<int> c[100002];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
bool t[100002];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin>>T;
	while(T--){
		memset(t, 0, sizeof(t));
		ans1=ans2=0;
		cin>>n>>m>>l>>v;
		for(int i = 1; i <= n; i++){
			cin>>d[i]>>u[i]>>a[i];
			cnt[i]=0;
		}
		for(int i = 1; i <= m; i++){
			cin>>p[i];
			c[i].clear();
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(p[j]<d[i]){
					continue;
				}
				if(sqrt(double(u[i]*u[i]+2*a[i]*(p[j]-d[i])))>v){
					c[j].push_back(i);
					cnt[i]++;
					if(!t[i]){
						t[i]=1;
						ans1++;
					}
				}
				if(sqrt(double(u[i]*u[i]+2*a[i]*(p[i]-d[i])))<=0){
					break;
				}
			}
		}
		for(int i = 1; i <= m; i++){
			q.push({c[i].size(), i});
		}
		while(!q.empty()){
			bool f=0;
			for(auto i : c[q.top().second]){
				if(cnt[i]==1){
					f=1;
					break;
				}
			}
			if(f==1){
				q.pop();
				continue;
			}
			ans2++;
			for(auto i : c[q.top().second]){
				cnt[i]--;
			}
			q.pop();
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}