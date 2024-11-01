#include <bits/stdc++.h>
using namespace std;
int a,m2,n2,x[5][14],ans=0;
char m,n;
int main(){
	memset(x,0,sizeof(x));
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n>>m;
		if(n=='D') n2=1;
		else if(n=='C') n2=2;
		else if(n=='H') n2=3;
		else if(n=='S') n2=4;
		if(m=='A') m2=1;
		else if(m=='T') m2=10;
		else if(m=='J') m2=11;
		else if(m=='Q') m2=12;
		else if(m=='K') m2=13
		else m2=m-'0';
		x[n2][m2]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(x[i][j]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
}