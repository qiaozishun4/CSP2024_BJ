#include <bits/stdc++.h>
using namespace std;
char w[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
int memo[4][13];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);	
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;
		if(s[0] == 'D'){
			int type = 0;
			if(s[1] >= '2' && s[1] <= '9') memo[type][s[1]-'0'-1]++;
			else if(s[1] == 'A') memo[type][0]++;
			else if(s[1] == 'T') memo[type][9]++;
			else if(s[1] == 'J') memo[type][10]++;
			else if(s[1] == 'Q') memo[type][11]++;
			else if(s[1] == 'K') memo[type][12]++;
		}else if(s[0] == 'C'){
			int type = 1;
			if(s[1] >= '2' && s[1] <= '9') memo[type][s[1]-'0'-1]++;
			else if(s[1] == 'A') memo[type][0]++;
			else if(s[1] == 'T') memo[type][9]++;
			else if(s[1] == 'J') memo[type][10]++;
			else if(s[1] == 'Q') memo[type][11]++;
			else if(s[1] == 'K') memo[type][12]++;
		}else if(s[0] == 'H'){
			int type = 2;
			if(s[1] >= '2' && s[1] <= '9') memo[type][s[1]-'0'-1]++;
			else if(s[1] == 'A') memo[type][0]++;
			else if(s[1] == 'T') memo[type][9]++;
			else if(s[1] == 'J') memo[type][10]++;
			else if(s[1] == 'Q') memo[type][11]++;
			else if(s[1] == 'K') memo[type][12]++;
		}else if(s[0] == 'S'){
			int type = 3;
			if(s[1] >= '2' && s[1] <= '9') memo[type][s[1]-'0'-1]++;
			else if(s[1] == 'A') memo[type][0]++;
			else if(s[1] == 'T') memo[type][9]++;
			else if(s[1] == 'J') memo[type][10]++;
			else if(s[1] == 'Q') memo[type][11]++;
			else if(s[1] == 'K') memo[type][12]++;
		}
	}
	int need = 0;
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 12; j++){
			if(memo[i][j] == 0) need++;
		}
	}
	cout << need;
	return 0;
}
