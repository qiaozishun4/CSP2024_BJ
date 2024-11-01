#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int T,n,m,L,V,s[N],e[N],d,v,a,p[N],ls,llss;
bool vis[N];
struct xd{
	int i,sl;
}sl[N];
bool cmp(xd A,xd B){
	return A.sl > B.sl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n >> m >> L >> V;
		for(int i = 1;i <= n+2;i++){
			vis[i] = 0;
			s[i] = e[i] = -1;
		}
		for(int i = 1;i <= m+2;i++){
			sl[i].i = sl[i].sl = 0;
		}
		for(int i = 1;i <= n;i++){
			cin >> d >> v >> a;
			
			if(a > 0){
				double t=0;
				if(V > v){
					t = 1.0*(V-v)/a;
					s[i] = v*t+0.5*a*t*t;
					s[i]++;
					e[i] = L;
					s[i] += d;
					if(s[i] > L){
						s[i] = e[i] = 0;
					}
				}
				if(V == v){
					s[i] = d+1;
					e[i] = L;
				}
				if(V < v){
					s[i] = d;
					e[i] = L;
				}
			}
			if(a == 0){
				
				if(v > V){
					s[i] = d;
					e[i] = L;
				}
			}
			if(a < 0){
				
				double t=0;
				if(v > V){
					t = 1.0*(V-v)/a;
					s[i] = d;
					e[i] = v*t+0.5*a*t*t+d;
					if(v*t+0.5*a*t*t == e[i]-d) e[i]--;
				}
			}
			//cout << s[i] << ' ' << e[i] << endl;
		}
		ls = 0;
		for(int i = 1;i <= m;i++){
			cin >> p[i];
			sl[i].i = i;
			for(int j = 1;j <= n;j++){
				if(s[j] <= p[i] && p[i] <= e[j]){
					if(!vis[j])ls++;
					vis[j] = 1;
					sl[i].sl++;
					//ls++;
				}
			}
		}
		/*
		
		*/
		for(int i = 1;i <= n+2;i++){
			vis[i] = 0;
		}
		sort(sl+1,sl+m+1,cmp);
		llss = 0;
		for(int ii = 1;ii <= m;ii++){
			int i = sl[ii].i;
			bool Use = 0;
			for(int j = 1;j <= n;j++){
				if(!vis[j] && s[j] <= p[i] && p[i] <= e[j]){
					//if()llss++
					vis[j] = 1;
					Use = 1;
					//ls++;
				}
			}
			if(Use) llss++;
			for(int k = 1;k <= m;k++){
				sl[k].sl = 0;
				sl[k].i = k;
				for(int j = 1;j <= n;j++){
					if(!vis[j] && s[j] <= p[k] && p[k] <= e[j]){
						sl[k].sl++;
					}
				}
			}
		}
		cout << ls << ' ' << m-llss << endl;
	}
	return 0;
}
