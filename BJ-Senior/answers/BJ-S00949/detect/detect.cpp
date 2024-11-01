#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 1e5+5;

int T;
int n,m,L,V;
int a[N],b[N];

long long cond[N];
int main(){
	ios::sync_with_stdio(0);
	#ifndef M_D
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	#endif
	cin >> T;
	while(T--){
		cin >> n >> m >> L >> V;
		long long d,v,a;
		for(int i = 1;i <= n;++i){
			cin >> d >> v >> a;
			if(V>=v && V>=v+(L-d)*a){
				cond[i]=LLONG_MAX;
			} else if(a>0) {
				cond[i]=v+ceil((V-v)/a)+1;
			} else if(a<0){
				cond[i]=-V-ceil((v-V)/a)-1;
			} else {
				cond[i]=LLONG_MAX;
			}
		}
		int cnt = 0;
		for(int i = 1;i <= m;++i){
			cin >> b[i];
			for(int i = 1;i <= n;++i){
				if( (cond[i]!=LLONG_MAX) && (cond[i] >= 0 && cond[i]-1 >= b[i]) || (cond[i]<= 0 && cond[i]+1 <= b[i]) ){
					++cnt;
					cond[i]=LLONG_MAX;
				}
			}
		}
		cout << cnt << ' ' << m-2 << '\n';
	}
	
	
	return 0;
}
