#include <bits/stdc++.h>
using namespace std;
int n;
int a[4][13];
string p;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	int x,y;
	for(int i = 0;i<4;i++){
		for(int j = 0;j<13;j++){
			a[i][j] = -1;
		}
	}
	for(int i = 0;i < n;i++){
		cin >> p;
		if(p[0] == 'D'){
			x = 0;
		}else if(p[0] == 'C'){
			x = 1;
		}else if(p[0] == 'H'){
			x = 2;
		}else if(p[0] == 'S'){
			x = 3;
		}

		if(p[1] == 'A'){
			y = 0;
		}else if(p[1] >= '2' && p[1] <= '9'){
			y = p[1] - '1';
		}else if(p[1] == 'T'){
			y = 9;
		}else if(p[1] == 'J'){
			y = 10;
		}else if(p[1] == 'Q'){
			y = 11;
		}else if(p[1] == 'K'){
			y = 12;
		}
		a[x][y] = 1;
	}
	int cnt = 0;
	for(int i = 0;i<4;i++){
		for(int j = 0;j<13;j++){
			if(a[i][j] == -1){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
