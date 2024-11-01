#include<bits/stdc++.h>
using namespace std;

const int sticks_num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

inline void my_out(const int times, const char data){
	for(int i = 1; i <= times; ++i)
		cout << data;
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while(t--){
		int x; cin >> x;
		if(x < 7){
			bool found = false;
			for(int i = 1; i <= 9; i++)
				if(sticks_num[i] == x){
					cout << i;
					found = true;
					break;
				}
			if(!found) cout << -1;
		}else if(x % 7 == 0){
			my_out(x / 7, '8');
		}else if(x % 7 == 1){
			cout << 10;
			my_out(x / 7 - 1, '8');
		}else if(x % 7 == 2){
			cout << 1;
			my_out(x / 7, '8');
		}else if(x % 7 == 3){
			if(x / 7 - 2 >= 0){
				cout << 200;
				my_out(x / 7 - 2, '8');
			}else{
				cout << 22;
			}
		}else if(x % 7 == 4){
			cout << 20;
			my_out(x / 7 - 1, '8');
		}else if(x % 7 == 5){
			cout << 2;
			my_out(x / 7, '8');
		}else if(x % 7 == 6){
			cout << 6;
			my_out(x / 7, '8');
		}
		cout << '\n';
	}
	return 0;
}