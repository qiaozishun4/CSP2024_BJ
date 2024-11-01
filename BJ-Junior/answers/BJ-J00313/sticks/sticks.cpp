#include<iostream>
#include<algorithm>
using namespace std;
const int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int cnt_min[] = {-1, -1, 1, 7, 4, 2, 0, 8};
string minn;
bool cmp(string a, string b){
	if(a.size() != b.size() ) return a.size() < b.size();
	else return a < b;
}
int cnt = 0;
void dfs(int k, string num){
	if(k < 0) return;
	if(k == 0){
		 if(!cmp(minn, num)) minn = num;
		 return;
	}
	for(int i = 7; i >= 2; i--){
		dfs(k-i, num+char(cnt_min[i]));
	}
}
 string sol(int x){
	if(x < 2) return "-1";
	if(x == 2) return "1";
	dfs(x, "0");
	return minn;
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		if(x % 7 == 0 && x) for(int i = 1; i <= x/7; i++) cout << 8;
		else if(x % 7 == 1 && x/7) {
			cout << 10;
			for(int i = 1; i < x/7; i++) cout << 8;
		}
		else cout << sol(x);
		cout << endl;
	}
}
