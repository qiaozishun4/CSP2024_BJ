#include <bits/stdc++.h>
using namespace std;
int n;
bool ipocker[60];
//D1-13,C14-26,H27-39,S40-52
//1 2 3 4 5 6 7 8 9 10 11 12 13
//A 2 3 4 5 6 7 8 9 T  J  Q  K
map<char, int> mp;
int cnt;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	mp['A'] = 0;
	mp['2'] = 1;
	mp['3'] = 2;
	mp['4'] = 3;
	mp['5'] = 4;
	mp['6'] = 5;
	mp['7'] = 6;
	mp['8'] = 7;
	mp['9'] = 8;
	mp['T'] = 9;
	mp['J'] = 10;
	mp['Q'] = 11;
	mp['K'] = 12;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		string str;
		cin >> str;
		char f = str[0], e = str[1];
		if(f == 'D'){
			ipocker[1 + mp[e]] = true;
		} else if(f == 'C'){
			ipocker[14 + mp[e]] = true;
		} else if(f == 'H'){
			ipocker[27 + mp[e]] = true;
		} else if(f == 'S'){
			ipocker[40 + mp[e]] = true;
		}
	}
	for(int i = 1; i <= 52; i++){
		if(ipocker[i] == false) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
