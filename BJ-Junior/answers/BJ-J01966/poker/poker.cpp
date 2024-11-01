#include<bits/stdc++.h>
using namespace std;
int o[5][15];
string a[100];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1; i<= n; i++){
		cin >> a[i];
		int t = 0;
		if(a[i][0] == 'D') t = 1;
		if(a[i][0] == 'C') t = 2;
		if(a[i][0] == 'H') t = 3;
		if(a[i][0] == 'S') t = 4;
		if(a[i][1] == 'A') o[t][1]++;
		if(a[i][1] == '2') o[t][2]++;
		if(a[i][1] == '3') o[t][3]++;
		if(a[i][1] == '4') o[t][4]++;
		if(a[i][1] == '5') o[t][5]++;
		if(a[i][1] == '6') o[t][6]++;
		if(a[i][1] == '7') o[t][7]++;
		if(a[i][1] == '8') o[t][8]++;
		if(a[i][1] == '9') o[t][9]++;
		if(a[i][1] == 'T') o[t][10]++;
		if(a[i][1] == 'J') o[t][11]++;
		if(a[i][1] == 'Q') o[t][12]++;
		if(a[i][1] == 'K') o[t][13]++;
	}
	int ans = 0;
	for(int i = 1; i<= 4; i++){
		for(int j = 1; j<= 13; j++){
			if(o[i][j] == 0) ans++;
		}
	}
	cout << ans <<endl;
	return 0;
}