#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 2;
int n, a[N], kill;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	// for(int i = 1; i <= n; i++){
	// 	cout << a[i] << endl;
	// }
	kill = n;
	int ans = n;
	for(int i = n; i >= 1; i--){
		while(kill >= 1 && a[kill] >= a[i]){
			kill--;
		}
		if(kill < 1){
			break;
		}
		ans--;
		kill--;
	}
	cout << ans << endl;
}