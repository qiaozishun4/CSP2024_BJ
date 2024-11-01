#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,ans=0;
bool a[5][5];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		int x,y;
		cin>>x>>y;
		if(x=='D'){
			if(y=='A') a[1][1]=true;
			if(y=='2') a[1][2]=true;
			if(y=='3') a[1][3]=true;
			if(y=='4') a[1][4]=true;
			if(y=='5') a[1][5]=true;
			if(y=='6') a[1][6]=true;
			if(y=='7') a[1][7]=true;
			if(y=='8') a[1][8]=true;
			if(y=='9') a[1][9]=true;
			if(y=='T') a[1][10]=true;
			if(y=='J') a[1][11]=true;
			if(y=='Q') a[1][12]=true;
			if(y=='K') a[1][13]=true;
		}else if(x=='C'){
			if(y=='A') a[2][1]=true;
			if(y=='2') a[2][2]=true;
			if(y=='3') a[2][3]=true;
			if(y=='4') a[2][4]=true;
			if(y=='5') a[2][5]=true;
			if(y=='6') a[2][6]=true;
			if(y=='7') a[2][7]=true;
			if(y=='8') a[2][8]=true;
			if(y=='9') a[2][9]=true;
			if(y=='T') a[2][10]=true;
			if(y=='J') a[2][11]=true;
			if(y=='Q') a[2][12]=true;
			if(y=='K') a[2][13]=true;
		}else if(x=='H'){
			if(y=='A') a[3][1]=true;
			if(y=='2') a[3][2]=true;
			if(y=='3') a[3][3]=true;
			if(y=='4') a[3][4]=true;
			if(y=='5') a[3][5]=true;
			if(y=='6') a[3][6]=true;
			if(y=='7') a[3][7]=true;
			if(y=='8') a[3][8]=true;
			if(y=='9') a[3][9]=true;
			if(y=='T') a[3][10]=true;
			if(y=='J') a[3][11]=true;
			if(y=='Q') a[3][12]=true;
			if(y=='K') a[3][13]=true;
		}else if(x=='S'){
			if(y=='A') a[4][1]=true;
			if(y=='2') a[4][2]=true;
			if(y=='3') a[4][3]=true;
			if(y=='4') a[4][4]=true;
			if(y=='5') a[4][5]=true;
			if(y=='6') a[4][6]=true;
			if(y=='7') a[4][7]=true;
			if(y=='8') a[4][8]=true;
			if(y=='9') a[4][9]=true;
			if(y=='T') a[4][10]=true;
			if(y=='J') a[4][11]=true;
			if(y=='Q') a[4][12]=true;
			if(y=='K') a[4][13]=true;
		}
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(a[i][j]==true) ++ans;
	cout<<ans;
	return 0;
}
