#include <bits/stdc++.h>
using namespace std;

string a[10]={"8", "10", "18", "200", "20", "28", "68"};
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		int n;
		string s;
		cin >> n;
		int p=n%7, pp=n/7;
		if(pp == 0){
			if(p == 1) s="-1";
			else if(p == 2) s="1";
			else if(p == 3) s="7";
			else if(p == 4) s="4";
			else if(p == 5) s="2";
			else if(p == 6) s="6";
		}
		else{
			pp--;
			if(p == 3){
				pp--;
			}
			if(pp >= 0) s=a[p];
			else s="22";
		}
		for(int i=1;i <= pp;i++){
			s+='8';
		}
		cout << s << "\n";
	}
	return 0;
}