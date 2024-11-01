#include <iostream>

using namespace std;

int n, k;

int main(){
	ios::sync_with_stdio(false);
	freopen("sticks.in", "r", stdin); freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		k = n % 7;
		if(n == 1) cout << "-1" << endl;
		else if(n == 2) cout << "1" << endl;
		else if(n == 3) cout << "7" << endl;
		else if(n == 4) cout << "4" << endl;
		else if(n == 5) cout << "2" << endl;
		else if(n == 6) cout << "6" << endl;
		else if(n == 10) cout << "22" << endl;
		else if(k == 0){
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}else if(k == 1){
			cout << "10";
			n -= 8;
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}else if(k == 2){
			cout << "1";
			n -= 2;
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}else if(k == 3){
			cout << "200";
			n -= 17;
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}else if(k == 4){
			cout << "20";
			n -= 11;
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}else if(k == 5){
			cout << "2";
			n -= 5;
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}else if(k == 6){
			cout << "6";
			n -= 6;
			for(int i = 1; i <= n / 7; ++i) cout << "8";
			cout << endl;
		}
	}
	return 0;
}