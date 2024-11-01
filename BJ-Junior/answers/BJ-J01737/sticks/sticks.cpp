#include <bits/stdc++.h>
using namespace std;
int t;
int sticks[10] = {6,2,5,20,4,20,6,3,7,60};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);	
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n;
		cin >> n;
		if(n == 1){
			cout << -1;
			continue;
		}
		if(n == 2){
			cout << 1;
			continue;
		}
		if(n == 3){
			cout << 7;
			continue;
		}
		if(n == 4){
			cout << 4;
			continue;
		}
		if(n == 5){
			cout << 2;
			continue;
		}
		if(n == 6){
			cout << 6;
			continue;
		}
		if(n == 8){
			cout << 10;
			continue;
		}
		if(n == 9){
			cout << 18;
			continue;
		}
		if(n == 10){
			cout << 22;
			continue;
		}
		if(n == 11){
			cout << 20;
			continue;
		}
		if(n == 12){
			cout << 28;
			continue;
		}
		if(n == 13){
			cout << 68;
			continue;
		}
		if(n%7==0){
			for(int j = 1; j <= n/7; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n % 7 == 1 && n >= 15){
			cout << 10;
			for(int j = 1; j <= n/7-1; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n%7 == 2 && n >= 15){
			cout << 18;
			for(int j = 1; j <= n/7-1; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n%7 == 3 && n >= 15){
			cout << 22;
			for(int j = 1; j <= n/7-1; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n%7 == 4 && n >= 15){
			cout << 20;
			for(int j = 1; j <= n/7-1; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n%7 == 5 && n >= 15){
			cout << 28;
			for(int j = 1; j <= n/7-1; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}else if(n%7 == 6 && n >= 15){
			cout << 68;
			for(int j = 1; j <= n/7-1; j++){
				cout << 8;
			}
			cout << endl;
			continue;
		}
	}
return 0;
}
