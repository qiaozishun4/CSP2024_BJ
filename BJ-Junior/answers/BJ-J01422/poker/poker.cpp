#include<bits/stdc++.h>
using namespace std;
int n;
int h[10][20];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		if(a=='D'){
			if(b=='A') h[1][1]++;
			if(b=='2') h[1][2]++;
			if(b=='3') h[1][3]++;
			if(b=='4') h[1][4]++;
			if(b=='5') h[1][5]++;
			if(b=='6') h[1][6]++;
			if(b=='7') h[1][7]++;
			if(b=='8') h[1][8]++;
			if(b=='9') h[1][9]++;
			if(b=='T') h[1][10]++;
			if(b=='J') h[1][11]++;
			if(b=='Q') h[1][12]++;
			if(b=='K') h[1][13]++;
		}
		else if(a=='C'){
			if(b=='A') h[2][1]++;
			if(b=='2') h[2][2]++;
			if(b=='3') h[2][3]++;
			if(b=='4') h[2][4]++;
			if(b=='5') h[2][5]++;
			if(b=='6') h[2][6]++;
			if(b=='7') h[2][7]++;
			if(b=='8') h[2][8]++;
			if(b=='9') h[2][9]++;
			if(b=='T') h[2][10]++;
			if(b=='J') h[2][11]++;
			if(b=='Q') h[2][12]++;
			if(b=='K') h[2][13]++;
		}
		else if(a=='H'){
			if(b=='A') h[3][1]++;
			if(b=='2') h[3][2]++;
			if(b=='3') h[3][3]++;
			if(b=='4') h[3][4]++;
			if(b=='5') h[3][5]++;
			if(b=='6') h[3][6]++;
			if(b=='7') h[3][7]++;
			if(b=='8') h[3][8]++;
			if(b=='9') h[3][9]++;
			if(b=='T') h[3][10]++;
			if(b=='J') h[3][11]++;
			if(b=='Q') h[3][12]++;
			if(b=='K') h[3][13]++;
		}
		else if(a=='S'){
			if(b=='A') h[4][1]++;
			if(b=='2') h[4][2]++;
			if(b=='3') h[4][3]++;
			if(b=='4') h[4][4]++;
			if(b=='5') h[4][5]++;
			if(b=='6') h[4][6]++;
			if(b=='7') h[4][7]++;
			if(b=='8') h[4][8]++;
			if(b=='9') h[4][9]++;
			if(b=='T') h[4][10]++;
			if(b=='J') h[4][11]++;
			if(b=='Q') h[4][12]++;
			if(b=='K') h[4][13]++;
		}
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(h[i][j]==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}