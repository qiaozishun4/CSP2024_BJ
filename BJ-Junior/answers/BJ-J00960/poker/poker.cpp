#include<bits/stdc++.h>

using namespace std;

bool flag[5][20];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		string s;
		cin >> s;
		int x;
		int y;
		if(s[0] == 'D'){
			x=1;
		}
		if(s[0] == 'C'){
			x=2;
		}
		if(s[0] == 'H'){
			x=3;
		}
		if(s[0] == 'S'){
			x=4;
		}
		
		
		if(s[1] == 'A'){
			y=1;
		}
		else if(s[1] == 'T'){
			y=10;
		}
		else if(s[1] == 'J'){
			y=11;
		}
		else if(s[1] == 'Q'){
			y=12;
		}
		else if(s[1] == 'K'){
			y=13;
		}
		else{
			y=s[1]-'0';
		}
		flag[x][y] = 1;
		
	}
	int cnt=0;
	for(int i=1;i<=4;++i){
		for(int j=1;j<=13;++j){
			if(flag[i][j] == 0){
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
