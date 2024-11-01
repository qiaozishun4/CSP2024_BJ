#include <bits/stdc++.h>
using namespace std;
int a[8] = {0,-1,1,7,4,2,6,8};
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	while (T--){
		cin >> n;
		if (n < 8) cout << a[n] << endl;
		else {
			if (n % 7 == 0){
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			} else if (n % 7 == 1){
				cout << 10;
				n -= 8;
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			} else if (n % 7 == 2){
				cout << "1";
				n -= 2;
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			} else if (n % 7 == 3){
				cout << "22";
				n -= 10;
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			} else if (n % 7 == 4){
				cout << "20";
				n -= 11;
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			} else if (n % 7 == 5){
				cout << "2";
				n -= 5;
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			} else {
				cout << "6";
				n -= 6;
				for (int i = 0;i < n;i += 7) cout << "8";
				cout << endl;
			}
		}
	}
	return 0;
}