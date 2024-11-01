/*
	未推出的尽可能少 -> 退出的尽可能多
	* 双指针
	* 
	* 136 136 136 136 136 136 136 136 2417 2417
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, l, r, ans, a[N];
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	l = 1, r = 2;
	sort(a + 1, a + 1 + n);
	while (r <= n){
		if(a[l] < a[r]) {  // 能打
			l++;
			r++;
			ans++;
		}
		else{ // 不能打 换个更强的
			r++;
		}
	}
	cout << n - ans;
	
	return 0;
}
