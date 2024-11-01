/*
	思路一： 枚举 + 验证 
	小木棍
	
	num[i] 表示  拼接数字i 需要的木棍数量
		消耗2根必拼 1
		消耗5根必拼 2
		消耗4根必拼 4
		消耗6根 拼 0 或 6 看位置
		消耗7根 拼 8
	
	f[i] 表示 i个木棍能拼接的最小的数字   -1无解
	
	满分思路： 贪心 + 状态机dp
	分情况  
	*	f[i][0] 0开头
	* 	f[i][1] 非0开头
	* 	每次左边拼一位
		f[i][0] = min(f[i-k1][0] + "0", f[i-k2][1]+"0" )(f[i-k][0] 有解)
		f[i][1] = min(f[i-k1][1] + "k", f[i - k2][0]+"k")


#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long ll;
int num[20] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6}; // num[i] 表示  拼接数字i 需要的木棍数量
int f[N][2]; // 存火柴数量
string g[N][2]; // 存具体数字

int main(){
	// 默认无解
	memset(f, -1, sizeof f);
	int n;
	cin >> n;
	
	


	return 0;
}	
*/

// 先写个暴力 假设答案在 500W 以内
#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long ll;
int num[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // num[i] 表示  拼接数字i 需要的木棍数量
int n, t, f[N], cnt; // f[i] 表示 i 根火柴拼的最小数字
int main(){
	
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out","w",stdout);
	
	memset(f, -1, sizeof f);
	
	// 预处理
	for(int i = 1; i <= N; i++){
		t = i, cnt = 0;
		while(t){
			cnt += num[t%10];
			t /= 10;
		}	
		if(f[cnt] == -1) f[cnt] = i;
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >>  t;
		if(t%7==0){
			for(int j = 0; j < t / 8; j++ ){
				cout << 8;
			}
			cout << endl;
		}
		else{
			cout << f[t] << endl;
		}
	}
	return 0;
}
