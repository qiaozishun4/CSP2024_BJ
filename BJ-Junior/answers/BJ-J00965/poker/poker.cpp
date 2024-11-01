#include <iostream>

using namespace std;

int n, ans;
bool vis[30][100];
string str;

int Get1(char c){
	if(c == 'D') return 1;
	if(c == 'C') return 2;
	if(c == 'H') return 3;
	if(c == 'S') return 4;
}

int Get2(char c){
	if(c == 'A') return 1;
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	return c - '0';
}

int main(){
	ios::sync_with_stdio(false);
	freopen("poker.in", "r", stdin); freopen("poker.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> str;
		vis[Get1(str[0])][Get2(str[1])] = 1;
	}
	for(int i = 1; i <= 4; ++i){
		for(int j = 1; j <= 13; ++j){
			if(!vis[i][j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}