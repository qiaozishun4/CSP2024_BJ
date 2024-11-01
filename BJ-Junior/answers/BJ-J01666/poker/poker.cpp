#include <bits/stdc++.h>
using namespace std;
int n,A,B,ans;
bool h[4][20];
char a,b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='D'){
			A=0;
		}
		if(a=='C'){
			A=1;
		}
		if(a=='H'){
			A=2;
		}
		if(a=='S'){
			A=3;
		}
		if(b=='A'){
			B=1;
		}
		else if(b=='T'){
			B=10;
		}
		else if(b=='J'){
			B=11;
		}
		else if(b=='Q'){
			B=12;
		}
		else if(b=='K'){
			B=13;
		}
		else{
			B=b-'0';
		}
		h[A][B]=1;
	}
	for(int i=0;i<=3;i++){
		for(int j=1;j<=13;j++){
			if(!h[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
