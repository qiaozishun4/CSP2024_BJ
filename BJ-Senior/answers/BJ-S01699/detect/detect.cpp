/*
	加速度==0 速度不变 等车都进来 开一个就行
 
	加速度 < 0 
	
	标记每个位置 超速的车有哪些
 1. 暴搜
 2. 只考虑 a >= 0 的情况  留最后一个就行
 
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;

ll T, n, m, L, V, d[N], v[N], a[N], p[N];
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while(T--){
		bool B = 0;
		cin >> n >> m >> L >> V;
		for(int i = 1; i <= n; i++)
			cin >> d[i] >> v[i] >> a[i];
		for(int i = 1; i <= m; i++)
			cin >> p[i];
		
		sort(p + 1, p + 1 + m);
		ll last = p[m], cnt = 0;
		// 考虑 a >= 0时   每辆车在最后测试点 会不会超速	
		for(int i = 1; i <= n; i++){
			if(a[i] > 0) B = 1;
			if(d[i] <= last){	// 能被最后测试点看到
				if((v[i] * v[i] + 2 * a[i] * (last - d[i])) > V * V ){
					cnt++;
				}
			}	
		}
		//if(B) cnt--;
		if(cnt != 0)
			cout << cnt <<" " << m-1 << endl;
		else
			cout << cnt <<" " << m << endl;
	}
	
	return 0;
}
