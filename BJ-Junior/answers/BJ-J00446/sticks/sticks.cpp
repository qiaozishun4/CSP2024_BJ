#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n == 1)cout << "-1\n";
		else if(n%7 == 0){
			int i = n/7;
			if(i != 0)while(i--)cout << 8;
			cout << '\n';
		}else if(n%7 == 1){
			int i = n/7-1;
			if(i > 0)while(i--)cout << 8;
			cout << "9\n";
		}else cout << "-1\n";
	}
}
