/*
 
枚举所有染色方案  2^n * n

2
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2
 
 */
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 200010;
ll T, n, ans, A[N], C[N];
int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	while(T--){
		ans = 0;
		cin >> n; 
		for(int i = 1; i <= n; i++){
			cin >> A[i];
		}
		
		ll c = 1ll << n;
		for(ll i = 0; i < c; i++){ // 二进制枚举 染色方案
			for(ll j = 0; j < n; j++){
				C[j+1] = (i >> j) & 1;
			}
			
			ll red = -1, blue = -1, tmp = 0;
			for(int j = 1; j <= n; j++){  // 计算得分
				//cout << "下标 颜色 数字 " << j <<" " << C[j] << " " << A[j] << endl;
				if(C[j] == 0){
					if(A[j] == red){
						tmp += A[j];
					}
					red = A[j];
				}
				if(C[j] == 1){
					if(A[j] == blue){
						tmp += A[j];
					}
					blue = A[j];
				}
			}
			//cout << "tmp" << tmp << endl;
			ans = max(ans, tmp); // 评价得分
			tmp = 0;
		}
		// cout <<"答案" << ans << endl; 
		cout << ans << endl;
		ans = 0;
	}
	
	return 0;
}
