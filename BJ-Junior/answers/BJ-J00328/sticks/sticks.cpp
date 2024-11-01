#include<iostream>
using namespace std;
int n;
const int ans[] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};
void mian(){
	cin >> n;
	if(n <= 21){
		cout << ans[n] << endl;
		return;
	}
	int a, b;
	b = n / 7 - 2;
	a = n % 7 + 14;
	cout << ans[a];
	for(int i = 1; i <= b; i++){
		cout << 8;
	}
	cout << endl;
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		mian();
	}
}
/*
#include<iostream>
using namespace std;
int n;
const int ans[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
inline int check(int i){
	int an = 0;
	while(i){
		an += ans[i % 10];
		i /= 10;
	}
	return an;
}
void mian(){
	cin >> n;
	if(n <= 1){
		cout << -1 << endl;
		return;
	}
	for(int i = 1; i <= 1e8; i++){
		if(check(i) == n){
			cout << i << endl;
			break;
		}
	}
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		mian();
	}
}
*/